# Controle de Servomotor com PWM na Raspberry Pi Pico W

## Descrição

Este projeto utiliza a Raspberry Pi Pico W para controlar um servomotor através da GPIO 22, ajustando sua posição com sinais PWM. Além disso, é realizado um experimento com o LED RGB na GPIO 12 utilizando a ferramenta educacional BitDogLab. O código implementa a movimentação periódica do servomotor e observa o comportamento do LED RGB.

## Componentes Utilizados

1. Raspberry Pi Pico W.
2. Servomotor.
3. LED RGB conectado à GPIO 12.

## DEMONSTRAÇÃO

[Vídeo de Demonstração](https://youtube.com/shorts/uefqdkTRf94)

## Funcionalidades do Projeto

1. **Configuração do PWM**

   - Definição da frequência do PWM para aproximadamente 50Hz (período de 20ms).

2. **Controle do Servomotor**

   - Posição de 180 graus: Ciclo de trabalho de 2.400μs (0,12%), com espera de 5 segundos.
   - Posição de 90 graus: Ciclo de trabalho de 1.470μs (0,0735%), com espera de 5 segundos.
   - Posição de 0 graus: Ciclo de trabalho de 500μs (0,025%), com espera de 5 segundos.

3. **Movimentação Periódica do Servomotor**

   - Alternância suave entre 0 e 180 graus.
   - Incremento de ciclo ativo de ±5μs com atraso de ajuste de 10ms.

4. **Experimento com LED RGB**
   - Utilizando a ferramenta BitDogLab, observar o comportamento do LED RGB na GPIO 12 ao executar o código.

## Como Compilar

Para compilar o programa, utilize um compilador C compatível para Raspberry Pi Pico W:

1. Configure o ambiente de desenvolvimento.
2. Compile o código gerando os arquivos `.uf2` e `.elf`.

## Como Executar

1. Carregue o arquivo `.uf2` na Raspberry Pi Pico W.
2. Execute o código e observe o comportamento do servomotor e do LED RGB.

## Requisitos

- Compilador C (gcc ou equivalente).
- Sistema operacional compatível.
- Biblioteca PWM para Raspberry Pi Pico.
- Ferramenta Educacional BitDogLab.

## Desenvolvedores

Equipe 2 - Grupo 3 - EmbarcaTech

- [Luiz Marcelo](https://github.com/devluinix)
