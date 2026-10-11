# Uso: . .\tools\env.ps1   (oppure & .\tools\env.ps1)
# Mette la toolchain vbcc nativa nel PATH e imposta VBCC.
$TOOLS = Join-Path $PSScriptRoot "..\\.toolchain\\vbcc-win\\vbcc" | Resolve-Path -ErrorAction SilentlyContinue
if (-not $TOOLS) {
    Write-Error "Toolchain mancante: scarica http://www.ibaug.de/vbcc/vbcc_win_x64.zip in .toolchain/ (vedi README)."
    return
}
$env:VBCC = $TOOLS.Path
$env:PATH = (Join-Path $TOOLS.Path "bin") + ";" + $env:PATH
Write-Output "VBCC=$env:VBCC"
vc -version 2>&1 | Select-Object -First 2
