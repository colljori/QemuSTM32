# QemuSTM32
Modélisation SystemC-TLM d’IP et intégration système matériel/logiciel


## Install

Pour libyaml >= 0.5.3: 
* DL sur la release sur le site/git
* cmake -DBUILD_SHARED_LIBS=ON
* cd build && make .. 
* ajouter la variable YAMLCPP_DIR dans l'environnement ( export ... )
* modifier Findyaml-cpp.cmake dans rabbits. Ajouter set(YAMLCPP_DIR $ENV{YAMLCPP_DIR}) après endif et dans find_fibrary ajouter $ENV{YAMLCPP_DIR}/build.


Pour libfdt >= 1.4.2, 
* cd sc-qemu 
* git submodule update --init dtc
