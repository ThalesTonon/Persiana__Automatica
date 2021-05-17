<img src="https://user-images.githubusercontent.com/7269314/78952616-93bfb700-7aac-11ea-8c5c-a9ff8fd4bf27.jpg"/>

<h1> Persiana Automática + App Inventor</h1> 

> Status do Projeto: Concluido ✔️


<h2>🚀 Começando </h2>

<p align="justify">Neste projeto é apresentado uma proposta de automação de persianas residenciais controlada por luminosidade. A maneira escolhida para essa automação foi o controle de um motor por meio de um microcontrolador, que recebe informação de um sensor de luminosidade. O protótipo tem a função de regular a angulação das lâminas de acordo com a intensidade da luz, após isso, a informação passa pelo microcontrolador que irá repassar os dados para o motor se adaptar com os comandos. Também foi implementado um modelo manual para que o usuário escolha a melhor opção de angulação para aquele determinado ambiente.</p>

<h2>📋 Pré-requisitos</h2>

<h3>De que coisas você precisa para executar o projeto?</h3>
<p align="justify"> Componentes: Arduino, Módulo Bluetooth (HC-05), Resistores, Sensor LDR, Motor de Passo, Driver Uln2003 e jumpers.
</p><br>

<h2>🛠 Tecnologias</h2>


<h2>⌨️ Executando os testes</h2> 

<h3>⚡Teste Sensor</h3>
<p>Para este teste foram utilizados um Arduino, LDR, resistor de 1KΩ como demostrado na imagem abaixo:</p>
<p align="center">
<img src="https://raw.githubusercontent.com/ThalesTonon/Persiana_Automatica/master/Imagens/CircuitoTesteSensor.png" width="300"/></p>
<p align="justify">Código utilizado: 
<a href="https://github.com/ThalesTonon/Persiana_Automatica/blob/master/Testes/TesteSensor.ino">Teste Sensor</a> 
</p>
<h3>⚙️Teste Motor de Passos</h3>
<p>Para que o motor faça movimentos específicos será necessária uma programação, sendo assim temos o exemplo abaixo com o código teste juntamente com a imagem do esquemático:</p>
<p align="center">
<img src="https://github.com/ThalesTonon/Persiana_Automatica/blob/master/Imagens/CircuitoTesteMotor.png?raw=true" width="150"/></p>
<p align="justify">Código utilizado: 
<a href="https://github.com/ThalesTonon/Persiana_Automatica/blob/master/Testes/TesteMotor.ino">Teste Motor de Passos</a> 
</p>
<h3>⚡⚙️Teste Integração</h3>
<p>Após analisar as etapas anteriores individualmente foi observado as características necessárias para que a integração seja feita de forma eficiente, por tanto a montagem da execução foi conectar as figuras em apenas um circuito.</p>
<p align="center">
<img src="https://github.com/ThalesTonon/Persiana_Automatica/blob/master/Imagens/CircuitoIntegracao.png?raw=true" width="150"/></p>
<p align="justify">Código utilizado: 
<a href="https://github.com/ThalesTonon/Persiana_Automatica/blob/master/Testes/Integracao.ino">Teste Integração
</a>
</p>
<h2>📱 Aplicativo</h2>

<p>
    A elaboração do aplicativo fará a comunicação do cliente com o Arduino, trazendo a função manual e automática para o projeto. Portanto ele foi feito criado usando uma aplicação de código aberto chamado MIT App Inventor e sua programação é em modo bloco, sendo assim, ele usa uma interface gráfica que permite o usuário arrastar e soltar objetos tornando a programação mais fácil e eficiente.
    Como a elaboração do projeto tem o objetivo fazer a conexão do celular com o módulo que passará a informação para o microcontrolador, foi implantado uma função que verificará se o Bluetooth está habilitado, caso não esteja ativado, o app pedirá para habilitar como na imagem abaixo.
    <p align="center">
    <img src="https://github.com/ThalesTonon/Persiana_Automatica/blob/master/Imagens/Aplicativo/HabilitaBluetooth.png?raw=true" width="300"/><p>
    Após ativação, o usuário estará habilitado para acessar as configurações como mostra na figura abaixo, então o usuário terá a opção de escolher entre falar os comandos e apenas selecionar os métodos, no modo fala é possível escolher entre diferentes posições apenas usando a voz, podendo também escolher entre o modelo automático e manual, mas no automático tudo dependerá da luminosidade e da configuração estipulada na programação e manual terá que mencionar qual ângulo que a persiana deverá ficar.
    <p align="center">
    <img src="https://github.com/ThalesTonon/Persiana_Automatica/blob/master/Imagens/Aplicativo/Configuracao.png?raw=true" width="300"/><p>
    Caso queira mais informações e detalhes sobre o desenvolvimento do app, basta acessar o link e poderá ter acesso a programação e componentes utilizados:
    <a href="https://gallery.appinventor.mit.edu/?galleryid=24acc3bb-760a-4143-8432-637c55a35a00">Link Para o APP</a> 
</p>

<h2>🏁 Resultado Final </h2> 

<h3> </h3>
<p>Como resultado final do projeto foram integrados os ciruitos acima juntamente com um módulo Bluetooth (HC-05), portanto foi habiltado que o usuário tenha controle da angulação da persiana:</p>
<p align="center">
<img src="https://github.com/ThalesTonon/Persiana_Automatica/blob/master/Imagens/CircuitoFinal.png?raw=true" width="300"/></p>
<p align="justify">Código utilizado: 
<a href="https://github.com/ThalesTonon/Persiana_Automatica/blob/master/Testes/CodigoFinal.ino">Teste Final</a> 
</p>


<h2> 🛠️ Construído com</h2>

<p align="justify">As seguintes ferramentas foram usadas na construção do projeto:</p>
<img src="https://www.arduino.cc/wiki/370832ed4114dd35d498f2f449b4781e/arduino.svg" width="50"/>
• <a href="https://www.arduino.cc/en/software">IDE Arduino</a> <br>
<img src="https://i.postimg.cc/x8XNX86J/download.png" width="50"/> 
• <a href="http://ai2.appinventor.mit.edu/#">App Inventor</a><br><br>

<h2> ✒️ Autores </h2>

<p align="justify"><b>Thales Carretero Tonon</b>  - Idealizador e responsavél pelo projeto</p>
<p align="justify"><b>Jean</b> - Mentor</p>
<p align="justify"><b>Thiago</b> - Mentor</p>

<h2>🎁 Gratidão</h2>

* Conte a outras pessoas sobre este projeto 📢
* Obrigado publicamente 🤓.