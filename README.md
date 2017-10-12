# QemuSTM32
Modélisation SystemC-TLM d’IP et intégration système matériel/logiciel


## Install

Pour libyaml >= 0.5.3: 
* DL sur la release sur le site/git
* modifier Findyaml-cpp.cmake dans rabbits pour qu'il aille chercher dans le dossier où il y a la nouvelle install. Le plus simple "export YAMLCPP_DIR=...". 
* Rajouter set(YAMLCPP_DIR $ENV{YAMLCPP_DIR} ) dans .cmake


Pour libfdt >= 1.4.2, 
* cd sc-qemu 
* git submodule update --init dtc
