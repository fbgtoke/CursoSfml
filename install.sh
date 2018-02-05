#!/bin/bash

sudo /etc/firewall/borrar.sh                                                                                                                                                
sudo zypper install libudev-devel
sudo zypper addrepo https://download.opensuse.org/repositories/games/openSUSE_Leap_42.3/games.repo                                                                          
sudo zypper refresh                                                                                                                                                         
sudo zypper install sfml2-devel     
