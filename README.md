# VirtualCriature-TheGame

Desenvolvedor: Marcos Gabriel <br>
Data da última atualização: 27/01/2024

## Descrição:
Este jogo é um projeto inspirado em bichinhos de estimação antigos como os tamagotchis e até alguns mais atuais como Pou. A ideia deste projeto inicialmente era apresentar um projeto divertido e interessante para aqueles que estão acabando de se inserir no mundo da programação de sistemas embarcados e ao mundo maker a partir do arduino, uma plataforma muito interessante para os iniciantes.

Assim, com o passar do tempo, este projeto se tornou uma forma de você desenhar a sua própria criatura de bolso, ou seja, seu próprio bichinho virtual do jeito que você quiser e cuidar dele. Para isso é necessário criar sua a pixel art da sua criatura na resolução `68x48` e utilizar alguma ferramenta que transforme sua pixel art em um bitmap que será adicionado ao código.

## Funcionalidades:
Grande parte das funções deste projeto são ferramentas e estruturas criadas em outros projetos criados anteriormente com o `BombDrop`, `MenuDisplay5110`, `RandomMath-TheGame`. Logo abaixo estão informadas as funções apenas deste projeto:

1. Função `updateStatus`:
Função responsável por atualizar os status ao decorrer do tempo, como por exemplo o gasto de energia e o aumento da fome. Também é responsável por verificar se o valor de xp atual é o suficiente para que o próximo nível seja alcançado.

2. Função `setNameAndStage`:
Função responsável por setar o nome e o estágio de evolução da criatura sempre que o jogo é iniciado e sempre que um novo nível é alcançado.

3. Função `drawSideMenu`:
Função responsável por desenhar o menu lateral da tela principal.

4. Função `loadData`:
Função responsável por carregar os dados salvos da memória EEPROM para nossa criatura.

5. Função `criatureEat`:
Função chamada sempre que você dá um alimento para sua criatura.