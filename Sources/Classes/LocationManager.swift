//
//  LocationManager.swift
//  iPass2.0NativeiOS
//

import Foundation
import CoreLocation

public class iPassLocationManager: NSObject, CLLocationManagerDelegate {
    public static let shared = iPassLocationManager()
    
    private let locationManager = CLLocationManager()
    public private(set) var lastLocation: CLLocation?
    
    override private init() {
        super.init()
        if Thread.isMainThread {
            self.setupLocationManager()
        } else {
            DispatchQueue.main.sync {
                self.setupLocationManager()
            }
        }
    }
    
    private func setupLocationManager() {
        locationManager.delegate = self
        locationManager.desiredAccuracy = kCLLocationAccuracyBest
    }
    
    public var authorizationStatus: CLAuthorizationStatus {
        if #available(iOS 14.0, macOS 11.0, *) {
            return locationManager.authorizationStatus
        } else {
            return CLLocationManager.authorizationStatus()
        }
    }
    
    public var isPermissionGranted: Bool {
        let status = authorizationStatus
        return status == .authorizedWhenInUse || status == .authorizedAlways
    }
    
    public func requestLocationAuthorization() {
        DispatchQueue.main.async { [weak self] in
            guard let self = self else { return }
            let status = self.authorizationStatus
            if status == .notDetermined {
                #if os(iOS)
                self.locationManager.requestWhenInUseAuthorization()
                #endif
            }
        }
    }
    
    public func startUpdatingLocation() {
        DispatchQueue.main.async { [weak self] in
            guard let self = self else { return }
            if self.isPermissionGranted {
                self.locationManager.startUpdatingLocation()
            }
        }
    }
    
    public func stopUpdatingLocation() {
        DispatchQueue.main.async { [weak self] in
            self?.locationManager.stopUpdatingLocation()
        }
    }
    
    // MARK: - CLLocationManagerDelegate
    
    public func locationManager(_ manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
        if let location = locations.last {
            self.lastLocation = location
        }
    }
    
    public func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        if status == .authorizedWhenInUse || status == .authorizedAlways {
            DispatchQueue.main.async {
                manager.startUpdatingLocation()
            }
        } else {
            DispatchQueue.main.async {
                manager.stopUpdatingLocation()
            }
        }
    }
    
    @available(iOS 14.0, macOS 11.0, *)
    public func locationManagerDidChangeAuthorization(_ manager: CLLocationManager) {
        let status = manager.authorizationStatus
        if status == .authorizedWhenInUse || status == .authorizedAlways {
            DispatchQueue.main.async {
                manager.startUpdatingLocation()
            }
        } else {
            DispatchQueue.main.async {
                manager.stopUpdatingLocation()
            }
        }
    }
    
    public func locationManager(_ manager: CLLocationManager, didFailWithError error: Error) {
        print("iPassLocationManager failed with error: \(error.localizedDescription)")
    }
    
    // MARK: - Generate Payload
    
    public func generateLocationPayload(ipAddress: String?) -> [String: Any] {
        let formatter = ISO8601DateFormatter()
        formatter.formatOptions = [.withInternetDateTime, .withFractionalSeconds]
        formatter.timeZone = TimeZone(secondsFromGMT: 0)
        let capturedAt = formatter.string(from: Date())
        
        if isPermissionGranted {
            let validIp: Any
            if let ip = ipAddress, !ip.isEmpty, ip != "Unable to get IP Address" {
                validIp = ip
            } else {
                validIp = NSNull()
            }
            
            let loc = lastLocation ?? locationManager.location
            let lat: Any = loc != nil ? loc!.coordinate.latitude : NSNull()
            let lon: Any = loc != nil ? loc!.coordinate.longitude : NSNull()
            let acc: Any = loc != nil ? loc!.horizontalAccuracy : NSNull()
            
            return [
                "latitude": lat,
                "longitude": lon,
                "accuracy": acc,
                "locationSource": "GPS",
                "permissionStatus": "granted",
                "ipAddress": validIp,
                "capturedAt": capturedAt
            ]
        } else {
            return [
                "latitude": NSNull(),
                "longitude": NSNull(),
                "accuracy": NSNull(),
                "locationSource": "IP",
                "permissionStatus": "denied",
                "ipAddress": NSNull(),
                "capturedAt": capturedAt
            ]
        }
    }
}
