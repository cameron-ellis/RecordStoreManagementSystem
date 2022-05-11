FROM ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y libopencv-dev g++

WORKDIR /src/

RUN apt-get update && \
    apt-get upgrade -y && \
    apt-get install -y git nlohmann-json3-dev

RUN git clone https://github.com/cameron-ellis/RecordStoreManagementSystem.git

WORKDIR /src/RecordStoreManagementSystem/build

RUN apt-get update && apt-get -y install cmake
RUN cmake ..
RUN make

CMD [ "./runSystem" ]