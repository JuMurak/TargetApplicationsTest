# Sobre
Este repositório foi criado, como requisito para entrega dos códigos do applications test Target.

Nesse repositório utilizamos docker para encapsular todos os programas e evitar que seja necessário instalar qualquer programa na máquina do usuário.

Para construir a imagem docker execute o seguinte comando:
```sh
sudo docker build -t applicationtest .
```

Para executar a imagem docker criada execute o seguinte comando:
```sh
sudo docker container run --env PROG=pergunta3 -it  applicationtest
```
Repare que para executar os diferentes programas você precisa alterar o valor da variável `PROG`. Os seguintes valores são suportados:
- `pergunta2`
- `pergunta3`
- `pergunta4`
- `pergunta5`
