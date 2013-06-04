@echo off
if "%1"=="" goto loop
copy invite%1.in invite.in >nul
echo Problem Test
echo Data %1
time<enter
invite
time<enter
fc invite.out invite%1.out
del invite.in
del invite.out
pause
goto end
:loop
for %%i in (0 1 2 3 4) do call %0 %%i
:end