echo "Instalação AirNinja"
arch=$(uname -m)
if [ "$arch" == "i686" -o "$arch" == "i386" -o "$arch" == "i486" -o "$arch" == "i586" ]; then
flag=1
else
flag=0
fi
FILE=game
cd game
make
if [ -e "$FILE" ]; then
echo "Jogo ja instalado!"
./game
else
cd ..
echo "Atualizando Sistema..."
sudo apt-get update
echo "Instalando Dependencias..."
sudo apt-get -y install libgl1-mesa-dev
sudo apt-get -y install libglu1-mesa-dev
sudo apt-get -y install cmake
sudo apt-get -y build-essential
sudo apt-get -y make
sudo apt-get -y libxcursor-dev
sudo apt-get install -y cmake g++ freeglut3-dev libxcursor-dev libpng12-dev libjpeg-dev libfreetype6-dev libgtk2.0-dev libasound2-dev libpulse-dev libopenal-dev libflac-dev libdumb1-dev libvorbis-dev libphysfs-dev
sudo apt-get install -y libpng-dev libz-dev libcurl4-gnutls-dev libfreetype6-dev libasound-dev
cd AirNinja Install
cd allegro5
sudo bash allegro5.sh
cd ..
cd opencv
sudo bash opencv.sh
echo "Instalando Jogo!"
fi
cd ..
cd ..
cd game
make
echo "Jogo Instalado com Sucesso!"
./game