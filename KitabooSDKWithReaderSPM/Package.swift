// swift-tools-version: 5.7
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
        // .package(url: /* package url */, from: "1.0.0"),
    ],
    targets: [
        // Targets are the basic building blocks of a package. A target can define a module or a test suite.
        // Targets can depend on other targets in this package, and on products in packages this package depends on.
        .binaryTarget(name: "KitabooSDKWithReader", url: "https://github.com/hardikhadwani-hurix/KitabooReaderSDK/releases/download/1.0/Kitaboo_Reader_SDK.xcframework.zip", checksum: "528830e2c0b38ef72fe8e1a8c1575a87d30d6681b6f0dba00e52f97af3d410bc"),
        .target(
            name: "KitabooSDKWithReaderSPM",
            dependencies: []),
        .testTarget(
            name: "KitabooSDKWithReaderTests",
            dependencies: ["KitabooSDKWithReaderSPM"]),
    ]
)
