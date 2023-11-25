# GS - Edge - 1ESA

Gustavo Kenzo Ozeki RM 98481
Vitor Shimizu RM 550390

Vídeo de apresentação: https://www.youtube.com/watch?v=WSmQv1pSn1Q&ab_channel=shimizu

Link do Wokwi: https://wokwi.com/projects/382189744734282753

SafeBeat - Utilizando Iot na saúde 

# O PROBLEMA 

Hoje, a sociedade enfrenta um grande desafio na interação entre saúde e tecnologia. A inovação e a tecnologia estão moldando como cuidamos da nossa saúde no futuro. A saúde é crucial para a qualidade de vida e para realizar nossos sonhos e potencial criativo. Portanto, é essencial lidar com os problemas urgentes nessa área. 

À medida que entramos em uma era cada vez mais digital e tecnológica, testemunhamos transformações profundas no campo da saúde. A prevenção de doenças destaca-se como uma área crucial, onde inovações baseadas em dados, wearables e aplicativos capacitam as pessoas a monitorar sua saúde de maneira eficaz, promovendo o autocuidado e a conscientização. 

A automação emerge como um elemento-chave, revolucionando procedimentos médicos. Cirurgias robóticas de precisão, sistemas de entrega de medicamentos autônomos e assistentes virtuais para pacientes estão se tornando realidade. Essas tecnologias não apenas aprimoram a eficiência dos procedimentos, mas também reduzem riscos e margens de erro, garantindo resultados mais consistentes e confiáveis. 

É essencial destacar que esse desafio não ocorre em um vácuo, mas alinha-se com as Metas de Desenvolvimento Sustentável propostas pela ONU, especificamente a Meta 3: "Assegurar uma vida saudável e promover o bem-estar para todos, em todas as idades". Esse enfoque não apenas impulsiona a inovação, mas também ressalta a importância de desenvolver soluções sustentáveis que promovam a saúde global.

# PROPOSTA DE SOLUÇÃO

A SafeBeat, pioneira em tecnologia de saúde, oferece uma experiência inovadora e crucial para o bem-estar das pessoas. Através de braceletes inteligentes, a empresa coleta dados de temperatura de pele, pressão sanguínea e batimentos cardíacos de forma contínua, 24 horas por dia. Essa abordagem proativa permite a detecção precoce de variações fora das faixas padrão, alertando instantaneamente médicos e familiares sobre a possibilidade de convulsões. 

O impacto direto dessa tecnologia é a promoção da segurança e saúde dos usuários. Ao fornecer alertas antecipados, a SafeBeat possibilita intervenções médicas rápidas e eficazes, reduzindo o risco e potencializando o cuidado personalizado. Além disso, a simplicidade de uso do bracelete e a interface amigável do sistema garantem uma experiência fluida para o usuário, integrando-se facilmente ao seu cotidiano e proporcionando tranquilidade tanto para quem utiliza o dispositivo quanto para seus entes queridos. A SafeBeat não apenas coleta dados, mas redefine a forma como lidamos com a prevenção e gestão de condições médicas, colocando a saúde nas mãos das pessoas.

# SafeBeat - Monitor de Temperatura IoT para Prevenção de Convulsões

Bem-vindo ao SafeBeat, uma solução de monitoramento de temperatura IoT dedicada à prevenção de convulsões. Este projeto utiliza o ESP32, um poderoso microcontrolador Wi-Fi e Bluetooth, em conjunto com um sensor de temperatura para medir e reportar a temperatura dos pacientes em tempo real. Além disso, o SafeBeat é capaz de acionar um alerta visual, acendendo um LED vermelho, quando a temperatura medida está fora da faixa considerada normal (abaixo de 36°C ou acima de 38°C), indicando um possível episódio de convulsão.

## Requisitos de Hardware:
- ESP32 microcontroller
- Sensor de Temperatura DHT22
- LED vermelho
- Fios de conexão
- Fonte de alimentação para o ESP32

## Configuração do Hardware:
1. Conecte o sensor de temperatura ao ESP32.
2. Conecte o LED vermelho ao ESP32.
3. Alimente o ESP32 com a fonte adequada.

## Configuração do Software:

### 1. Ambiente de Desenvolvimento
- Certifique-se de ter o ambiente de desenvolvimento Arduino IDE configurado com suporte ao ESP32.

### 2. Bibliotecas Necessárias
- Instale as bibliotecas necessárias, incluindo a biblioteca para o sensor de temperatura.

### 3. Configuração das Credenciais Wi-Fi
- Abra o código-fonte no Arduino IDE.
- Insira as informações de sua rede Wi-Fi no código.

### 4. Ajustes de Limiar de Temperatura
- Modifique os valores de temperatura no código para atender às necessidades específicas da sua aplicação.

### 5. Carregando o Código no ESP32
- Conecte o ESP32 ao computador via USB.
- Selecione a porta correta e o modelo de placa no Arduino IDE.
- Carregue o código para o ESP32.

## Executando o SafeBeat:
1. Alimente o ESP32.
2. Aguarde até que o dispositivo se conecte à rede Wi-Fi.
3. O sensor de temperatura iniciará a leitura automaticamente.
4. O LED vermelho acenderá se a temperatura estiver fora dos limites especificados.

## Observações Importantes:
- Certifique-se de que o ESP32 tenha uma conexão estável com a rede Wi-Fi.
- Verifique a correta conexão do sensor de temperatura e do LED vermelho.
- Faça os ajustes necessários nos limiares de temperatura conforme apropriado para o contexto clínico.

O SafeBeat foi desenvolvido como parte de nossa dedicação à saúde dos pacientes, especialmente na prevenção de convulsões. Este README fornece instruções claras para configurar e executar o SafeBeat.
