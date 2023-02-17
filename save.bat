mkdir %1
cp main.cpp "%1/%1.cpp"
if not "%2"=="+Commit" goto end
git add "./%1"
git commit -m "%1: added solution"
:end
echo "Done"
