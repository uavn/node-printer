# Build Win32 64bit
node-pre-gyp configure --target=$env:nodejs_version
node-pre-gyp build package --target=$env:nodejs_version --target_arch=x64

# Build Win32 32bit
node-pre-gyp configure --target=$env:nodejs_version
node-pre-gyp build package --target=$env:nodejs_version --target_arch=ia32

if ($env:build_electron -ne "true") {
  echo "Skipping Electron Build as flag not set"
  return
}

# Build Electron Versions
./tools/buildElectronWindows.ps1 1.2.8
./tools/buildElectronWindows.ps1 1.3.8
./tools/buildElectronWindows.ps1 1.4.6
./tools/buildElectronWindows.ps1 1.7.12
./tools/buildElectronWindows.ps1 6.0.7
