INFORMATION
======
This repository is a modified version of [srsRAN Project](https://www.srsran.com/) to include srsUE and ZMQ within the docker-based deployment included in the original repository. For that, I have included srsRAN_4G (which cotains a 5G UE prototype) as part of the provided docker-compose file, I have added the required compilation flags within the gitlab ci script and finally, I have included a configuration file for the gNB taken from the documentation ([srsRAN gNB with srsUE](https://docs.srsran.com/projects/project/en/latest/tutorials/source/srsUE/source/index.html#srsran-gnb-with-srsue))

!! IMPORTANT: by default, the docker compose file starts the UE and then, runs a ping command towards the 5G Core.

Steps
====================
- Requirements:

  - [Docker](https://docs.docker.com/engine/install/)
  - [Docker Compose](https://docs.docker.com/compose/install/)

```bash
# Linux / Windows WSL
git clone https://github.com/noeliamp/srsRAN_Project_zmq_docker.git

cd srsRAN_Project_zmq_docker/docker

docker compose up --build
```

srsRAN Project
==============

[![Build Status](https://github.com/srsran/srsRAN_Project/actions/workflows/ccpp.yml/badge.svg?branch=main)](https://github.com/srsran/srsRAN_Project/actions/workflows/ccpp.yml)
[![OpenSSF Best Practices](https://www.bestpractices.dev/projects/7868/badge)](https://www.bestpractices.dev/projects/7868)

The srsRAN Project is a complete 5G RAN solution, featuring an ORAN-native CU/DU developed by [SRS](http://www.srs.io).

The solution includes a complete L1/2/3 implementation with minimal external dependencies. Portable across processor architectures, the software has been optimized for x86 and ARM. srsRAN follows the 3GPP 5G system architecture implementing the functional splits between distributed unit (DU) and centralized unit (CU). The CU is further disaggregated into control plane (CU-CP) and user-plane (CU-UP).

See the [srsRAN Project](https://www.srsran.com/) for information, guides and project news.

Build instructions and user guides - [srsRAN Project documentation](https://docs.srsran.com/projects/project).

Community announcements and support - [Discussion board](https://www.github.com/srsran/srsran_project/discussions).

Features and roadmap - [Features](https://docs.srsran.com/projects/project/en/latest/general/source/2_features_and_roadmap.html).

Build Preparation
-----------------

* Build tools:
  * cmake:               <https://cmake.org/>
  
* Mandatory requirements:
  * libfftw:             <https://www.fftw.org/>
  * libsctp:             <https://github.com/sctp/lksctp-tools>
  * yaml-cpp:            <https://github.com/jbeder/yaml-cpp>
  * PolarSSL/mbedTLS:    <https://www.trustedfirmware.org/projects/mbed-tls/>
  * googletest:          <https://github.com/google/googletest/>

You can install the build tools and mandatory requirements for some example distributions with the commands below:

<details open>
<summary>Ubuntu 22.04</summary>

```bash
sudo apt-get install cmake make gcc g++ pkg-config libfftw3-dev libmbedtls-dev libsctp-dev libyaml-cpp-dev libgtest-dev
```

</details>
<details>
<summary>Fedora</summary>

```bash
sudo yum install cmake make gcc gcc-c++ fftw-devel lksctp-tools-devel yaml-cpp-devel mbedtls-devel gtest-devel
```

</details>
<details>
<summary>Arch Linux</summary>

```bash
sudo pacman -S cmake make base-devel fftw mbedtls yaml-cpp lksctp-tools gtest
```

</details>

The srsRAN Project supports split-8 and split-7.2 fronthaul. Split-8 fronthaul is supported via UHD for USRP devices:

* UHD:                 <https://github.com/EttusResearch/uhd>
  * See UHD documentation for installation instructions.

Build Instructions
------------------

Download and build srsRAN:

```bash
git clone https://github.com/srsran/srsRAN_Project.git
cd srsRAN_Project
mkdir build
cd build
cmake ..
make
make test
```

PHY layer tests use binary test vectors and are not built by default. To enable, see the [docs](https://docs.srsran.com/projects/project/en/latest/user_manuals/source/installation.html).
