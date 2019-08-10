# Flash my firmware

$ErrorActionPreference = "Stop"

# Get teensy loader first if not exist
if (-not (Test-Path "teensy_loader_cli.exe")) { 
    Write-Output "Fetchin teensy for flashing..."
    if (-not (Test-Path "teensy_loader_cli_windows.zip")) { 
        Invoke-WebRequest -Uri "https://www.pjrc.com/teensy/teensy_loader_cli_windows.zip" -OutFile "teensy_loader_cli.zip"
    }
    Expand-Archive -Path ".\teensy_loader_cli.zip" -DestinationPath "."
    Remove-Item ".\teensy_loader_cli.zip"
}
if (-not (Test-Path "teensy_loader_cli.exe")) { 
    Write-Error "Unable to fetch teensy loader cli"
    Exit 1
}

.\teensy_loader_cli.exe -w -v --mcu=atmega32u4 build/ergodox_ez_ciantic.hex