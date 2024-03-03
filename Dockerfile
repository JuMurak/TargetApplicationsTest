FROM alpine

# copiando os arquivos para a imagem
COPY *.c Makefile *.json .

# instalando os programas necessários
RUN apk update && apk add build-base cmake git

# clonando o repositório da lib cJSON
RUN git clone https://github.com/DaveGamble/cJSON.git

# compilando a lib cJSON
RUN cd cJSON && mkdir build && cd build && cmake .. -DBUILD_SHARED_AND_STATIC_LIBS=On && make install

# compilando todos os exercícios
RUN make all

# executar um exercício específico
CMD ["sh", "-c", "./${PROG}"]
