# Build my fimware

# Update with:
# docker pull qmkfm/qmk_firmware

docker run --rm -it `
    -v ${pwd}/build:/out `
    -v ${pwd}/keymap:/qmk_firmware/keyboards/ergodox_ez/keymaps/ciantic `
    -w /qmk_firmware `
    "qmkfm/qmk_firmware" "/bin/bash" "-c" "make ergodox_ez:ciantic && cp /qmk_firmware/.build/ergodox_ez_ciantic.hex /out"

if (-not $?) {
    Write-Error "Building failed"
    Exit 1
}