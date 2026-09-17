@echo off
setlocal
rem Homework 3 — 문제별 채점 (3개 테스트 케이스 기준)

g++ main.cpp problem1.cpp problem2.cpp problem3.cpp problem4.cpp ^
    -o hw3_main.exe -std=c++17 > nul 2>&1
if errorlevel 1 (
    echo Compile Error
    exit /b 1
)

for %%j in (1 2 3) do (
    .\hw3_main.exe Test\case%%j.txt > Test\output%%j.txt 2>nul
    if errorlevel 1 (
        echo Runtime Error (case%%j)
        del hw3_main.exe 2>nul
        exit /b 1
    )
)
del hw3_main.exe 2>nul

set all_pass=true

for %%i in (1 2 3 4) do (
    powershell -NoProfile -ExecutionPolicy Bypass -Command ^
        "$i = %%i; $next = $i + 1; $pass = $true; foreach ($j in 1,2,3) { $extract = { param($f) $c = Get-Content $f; $o = @(); $in = $false; foreach ($l in $c) { if ($l -match ('=== Problem ' + $i + ':')) { $in = $true }; if ($in -and $i -lt 4 -and $l -match ('=== Problem ' + $next + ':')) { break }; if ($in) { $o += $l } }; ($o -join \"`n\").TrimEnd() }; $a = (& $extract \"Test\output$j.txt\") -replace \"`r\"; $e = (& $extract \"Test\expected$j.txt\"); if ($a -ne $e) { $pass = $false; break } }; if ($pass) { Write-Host \"Problem $i`: PASS\" } else { Write-Host \"Problem $i`: FAIL\"; exit 1 }" ^
    || set all_pass=false
)
