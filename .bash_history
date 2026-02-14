ls -la
pwd
cd
cd /home
cd ta2830
ls -la
mkdir Assignment 1
mkdir Assignment_1
sudo mkdir Assignment_1
cp ../tanmayagarwal/.git .
cp ../ta2830/.git .
cp -r ../ta2830/.git .
cd ..
cd tanmayagarwal
cd /home/tanmayagarwal
cp -r ../ta2830/.git .
git config --global user.email "ta2830@columbia.edu"
git config --global user.name "ta2830"
git push
ls ~/.ssh
ssh-keygen -t ed25519 -C "ta2830@columbia.edu"
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_ed25519
cat ~/.ssh/id_ed25519.pub
ssh -T git@github.com
git push origin main
git pull --rebase origin main
git push origin main
git status
git add -A
git rebase --continue
git push origin main
git push --force-with-lease origin main
git restore --staged .
git rm --cached -r .ssh 2>/dev/null || true
git rm --cached -r .cursor .cursor-server 2>/dev/null || true
cat >> .gitignore <<'EOF'
# Local/IDE
.cursor/
.cursor-server/
.vscode/
*.log

# Secrets / SSH
.ssh/
.env
EOF

git add .gitignore
git commit -m "Add gitignore for local/secret files"
git pull --rebase origin main
git push origin main
gcc -O3 -Wall -o dp1 dp1.c
tanmayagarwal@instance-hpml-1:~$ gcc -O3 -Wall -o dp1 dp1.c
sudo apt update
sudo apt install build-essential -y
gcc --version
gcc -O3 -Wall -o dp1 dp1.c
cd/Assignment_1
cd /Assignemnt_1
cd home/Assignemnt_1
ls -la
gcc -O3 -Wall -o dp1 dp1.c
cd Assignment_1
ls
gcc -O3 -Wall -o dp1 dp1.c
gcc -03 -Wall -o dp1 dp1.c
gcc -O3 -Wall -o dp1 dp1.c
cat /etc/os-release
which gcc || echo "no gcc"
gcc --version
echo '#include <stdio.h>\nint main(){return 0;}' > t.c
gcc t.c -o t && echo "compile OK" || echo "compile FAILED"
gcc --version
gcc t.c -o t && ./t && echo OK
cat > t.c <<'EOF'
#include <stdio.h>
int main(){ return 0; }
EOF

gcc t.c -o t && ./t && echo OK
gcc -O3 -Wall -o dp1 dp1.c
free -h
sudo apt update
sudo apt install -y build-essential python3 python3-pip
python3 -m pip install --user numpy matplotlib
./dp1 1000 10
gcc -O3 -Wall -o dp1 dp1.c
gcc -O3 -Wall -o dp2 dp2.c
gcc -O3 -Wall -o dp1 dp1.c
./dp1 1000 10
./dp1 1000000 1000
./dp1 300000000 20
gcc -O3 -Wall -o dp2 dp2.c
./dp2 1000 10
./dp2 1000000 1000
./dp2 300000000 20
ls /opt/intel/oneapi 2>/dev/null
ldconfig -p | grep openblas
gcc -O3 -Wall -o dp3 dp3.c -lopenblas -lpthread -lm
gcc -O3 -Wall -o dp3 dp3.c
gcc -O3 -Wall -o dp3 dp3.c -lopenblas -lpthread -lm
./dp3 1000 10
./dp3 1000000 1000
./dp3 300000000 20
python3 dp4.py 1000 10
python3 dp4.py 1000000 1000
python3 dp4.py 300000000 20
