# VirtualCriature-TheGame

Desenvolvedor: Marcos Gabriel <br>
Data da última atualização: 27/01/2024

## Descrição:
Este jogo é um projeto inspirado em bichinhos de estimação antigos como os tamagotchis e até alguns mais atuais como Pou. A ideia deste projeto inicialmente era apresentar um projeto divertido e interessante para aqueles que estão acabando de se inserir no mundo da programação de sistemas embarcados e ao mundo maker a partir do arduino, uma plataforma muito interessante para os iniciantes.

Com o desenvolvimento do projeto, foram surgindo ideias de colocar menus e mini games para que fosse possível acessar os status da sua criatura virtual e poder brincar com ela. Isto deu origem à outros projetos que podem ser encontrados no meu github.

Assim, com o passar do tempo, este projeto se tornou uma forma de você desenhar a sua própria criatura de bolso, ou seja, seu próprio bichinho virtual do jeito que você quiser e cuidar dele. Para isso é necessário criar sua a pixel art da sua criatura na resolução `68x48` e utilizar alguma ferramenta que transforme sua pixel art em um bitmap que será adicionado ao código (deixairei nas referências links para as ferramentas que eu uso).

## Circuito Eletrônico
<img src="https://cdn.discordapp.com/attachments/1153711382336909332/1163203943237689404/image.png?ex=653eb917&is=652c4417&hm=aafb61461d30b2c1abee0a6c10e71c59c9cdcf73e34c3c1c1630b3395ad9d880&" />

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

6. Função `criatureConfig`:
Função responsável por acessar as seguintes configurações do jogo: ligar/desligar luz de fundo e salvar o jogo.

7. Função `playGame`:
Função reponsável por acessar os mini games para se divertir com sua criatura.

8. Função `menuStatus`:
Função responsável por apresentar na tela os status da criatura (nivel, xp, humor, comida, energia);

## Últimas observações:
Fiquei feliz com o resultado deste projeto, entretanto acredito que há muitas coisas a serem melhoradas. Caso encontre algo a ser melhorado, por favor entre em contato.

## Referências:

- Ferramenta para criação de menus para um display Nokia 5110: https://github.com/marcosgabrielsr/MenuDisplay5110

- Minigame Bomb Drop: https://github.com/marcosgabrielsr/BombDrop

- Minigame Random Math: https://github.com/marcosgabrielsr/RandomMath-TheGame

- Site para criação de suas próprias pixel arts: https://www.pixilart.com/

- Site para conversão de imagens para bitmaps: https://javl.github.io/image2cpp/