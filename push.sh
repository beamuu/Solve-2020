echo "Pulling from the repository..."
git pull origin master
echo"\n\n\n"
echo "Pushing to the repository..."
git add .
git commit -m $1
git push -u origin master
echo "\nProcess done"
