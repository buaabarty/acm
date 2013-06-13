@echo off
if "%1"=="" goto loop
copy transfer%1.in transfer.in >nul
echo Problem Test
echo Data %1
time<enter
transfer
time<enter
fc transfer.out transfer%1.out
del transfer.in
del transfer.out
pause
goto end
:loop
for %%i in (0 1 2 3 4) do call %0 %%i
:end