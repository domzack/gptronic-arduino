# GPTRONIC Arduino Serial Sender

Este projeto permite enviar mensagens para o painel GPTRONIC utilizando comunicação SERIAL RS232 via Arduino.

## Arquivo principal

[index.ino](index.ino)

### O que faz?

O arquivo define a função `PrintLed`, que envia uma mensagem de texto para o painel GPTRONIC. A mensagem é enviada byte a byte, seguindo o protocolo do painel, incluindo cabeçalho, comandos de rolagem e commit.

### Como funciona?

- Substitui todos os caracteres '+' por espaço na mensagem (útil para interfaces ethernet).
- Envia cabeçalho e comandos específicos via `Serial2`.
- Envia a mensagem byte a byte.
- Finaliza com um byte de commit.

### Uso

1. Conecte o Arduino à interface RS232 do painel GPTRONIC.
2. Certifique-se de que o Arduino está configurado para usar `Serial2` na velocidade correta.
3. No seu código, chame a função:

```cpp
PrintLed("Sua mensagem aqui");
```

### Exemplo completo

```cpp
void setup() {
  Serial2.begin(9600); // Ajuste a velocidade conforme o painel
}

void loop() {
  PrintLed("Bem-vindo ao GPTRONIC!");
  delay(5000);
}
```

### Parâmetros

- `message`: String a ser exibida no painel. Use espaços ou '+' (que será convertido para espaço).

### Observações

- O protocolo utilizado é específico do painel GPTRONIC.
- O tempo de delay entre bytes pode ser ajustado conforme necessário.
- Certifique-se de que a pinagem do Arduino está correta para comunicação RS232.

## Autor

Rodrigo Daniel Zacarias ME
