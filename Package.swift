// swift-tools-version: 5.5
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "KitabooSDKWithReaderSPM",
    platforms: [.iOS("13.0")],
    products: [
        // Products define the executables and libraries a package produces, and make them visible to other packages.
        .library(
            name: "KitabooSDKWithReaderSPM",
            targets: ["KitabooSDKWithReaderSPM","KitabooSDKWithReader"]),
    ],
    dependencies: [
        // Dependencies declare other packages that this package depends on.
        .package(url: "https://github.com/hardikhadwani-hurix/KitabooReaderSDKSPM", from: "1.0.1"),
    ],
     targets: [
        // Targets are the basic building blocks of a package. A target can define a module or a test suite.
        // Targets can depend on other targets in this package, and on products in packages this package depends on.
        .binaryTarget(name: "KitabooSDKWithReader", url: "https://github.com/hardikhadwani-hurix/KitabooSDKWithReader/releases/download/1.0.0/KitabooSDKWithReader.xcframework.zip", checksum: "58dc4444d27d0a0d666f82fa9a4c30457a54c4b9c5b47de57b5816a316a8e605"),
        .target(
            name: "KitabooSDKWithReaderSPM",
            dependencies: [
                .product(name: "KitabooReaderSDKSPM", package: "KitabooReaderSDKSPM"),
            ]),
        .testTarget(
            name: "KitabooSDKWithReaderTests",
            dependencies: ["KitabooSDKWithReaderSPM"]),
    ]
        
)
