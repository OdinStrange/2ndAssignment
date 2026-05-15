@echo off
setlocal enabledelayedexpansion

:: 1. 현재 원격 저장소 URL 가져오기
for /f "tokens=*" %%a in ('git remote get-url origin 2^>nul') do set "OLD_URL=%%a"

if not defined OLD_URL (
    echo [Error] 현재 폴더에서 origin 원격 주소를 찾을 수 없습니다.
    pause
    exit /b
)

:: 2. 조직명 치환 (NbcampUnreal -> NBcampUnrealTrack)
set "NEW_URL=%OLD_URL:NbcampUnreal=NBcampUnrealTrack%"

echo.
echo ------------------------------------------------------------
echo [기존 주소] %OLD_URL%
echo [변경 주소] %NEW_URL%
echo ------------------------------------------------------------
echo.

:: 3. 주소 업데이트 실행 (괄호 제거로 구문 오류 방지)
if "%OLD_URL%"=="%NEW_URL%" (
    echo [!] 변경할 패턴이 없거나 이미 주소가 최신입니다.
) else (
    git remote set-url origin !NEW_URL!
    echo [OK] 원격 주소 업데이트 성공!
)

echo.
echo [최종 연결 확인]
git remote -v
echo.
echo ------------------------------------------------------------
echo 작업을 완료했습니다. 아무 키나 누르면 창이 닫힙니다.
pause > nul
exit