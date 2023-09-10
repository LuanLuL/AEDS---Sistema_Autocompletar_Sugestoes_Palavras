 <section>   
    <h1>📢 AEDS: Sistema de sugestão de palavras</h1>   
    <p>
        Criado em setembro de 2023, o projeto de<strong> sugestão de palavras</strong> foi desenvolvido em virtude de atender as demandas do curso de Algoritimo e Estrutura de Dados, ministrado pelo professor <a href="https://www.linkedin.com/in/michelpiressilva/?originalSubdomain=br" target="_blank">Michel Pires Da Silva</a> no Centro Federal de Educação Tecnológica de Minas Gerais (<a href="https://www.divinopolis.cefetmg.br/" target="_blank">CEFET-MG</a>).
    </p>
    <p>
        Vale ressaltar que o sistema de sugestão de palavras é uma continuação do projeto <a href="https://github.com/LuanLuL/AEDS---Top_K_Itens" target="_blank">Top K itens</a>, o qual tem a capacidade de contar as palavras mais frequentes em um texto. Portanto, o sistema de<strong> sugestão de palavras</strong> segue as diretrizes do projeto passado.
    </p>
</section>
<section>
    <h2>🛠 Objetivo</h2>
    <p>
        O objetivo deste projeto é criar uma ferramenta ou programa que, dada uma palavra específica (denominada "busca") e um texto como entrada, seja capaz de gerar sugestões para a próxima palavra que poderia seguir a "busca" com base na análise das palavras mais recorrentes no texto.
    </p>
    <p>
        A utilidade desse projeto pode estar relacionada a várias aplicações, como correção automática de texto, previsão de palavras em campos de busca, sugestão de palavras em aplicativos de mensagens, entre outras. O projeto visa melhorar a experiência do usuário ao ajudar na seleção da próxima palavra em uma frase ou texto, tornando-a mais rápida, precisa e relevante.
    </p>
</section>
<section>
    <h2>🌐 Coleta de dados</h2>
    <p>
        Nesta seção, é descrito o processo de aquisição de dados a partir de um arquivo denominado "pesquisar.txt". Esse arquivo contém um catálogo de palavras-chave que servirão como base para a obtenção de sugestões relacionadas em diversos arquivos de texto, conforme o interesse do usuário.
    </p>
    <p>
        O sistema permite ao usuário especificar uma lista de palavras-chave no arquivo "pesquisar.txt". Nesse sentido, cada palavra a ser buscada deve ser colocada em uma linha separada. Feito isso, o software consiguirá coletar cada palavra-chave e armazena-la temporariamente em uma estrutura de dados interna.
    </p>
    <p>
        No que se refere à inserção de inputs de entrada, segue-se a mesma lógica adotada no projeto anterior (<a href="https://github.com/LuanLuL/AEDS---Top_K_Itens" target="_blank">Top K itens</a>).
    </p>
</section>
<section>
    <h2>🚧 Implementação do Sistema</h2>
    <p>
        Após a leitura do arquivo "pesquisar.txt", o sistema está pronto para iniciar o processo de busca das palavras-chave especificadas. Para cada palavra-chave presente na lista, o sistema executa um conjunto de ações bem definidas.
    </p>
    <p>
        Primeiramente, o sistema abre cada um dos arquivos de entrada disponíveis para busca. Cada arquivo representa uma fonte de texto onde as palavras-chave serão pesquisadas. Por acaso, se uma palavra-chave não existir em um arquivo específico, o sistema pula automaticamente para o próximo arquivo de entrada, economizando tempo e recursos de processamento. 
    </p>
    <p>
        No entanto, quando uma palavra-chave é encontrada em um arquivo de entrada, o sistema executa a etapa de busca das K palavras mais relevantes dentro do contexto. Esta etapa implica na execução da tokenização do texto, onde as palavras são divididas em unidades individuais, e posterior armazenamento dessas palavras em uma estrutura de dados conhecida como MaxHeap. O objetivo principal desse processo é contar e registrar as frequências de ocorrência de cada palavra no texto analisado.
    </p>
    <p>
         Tendo identificado as K palavras mais relevantes estas são armazenadas em três diferentes estruturas de dados
    </p>
    <div>
       <h3>⚙ Estuturas de dados</h3>
        <p>
        </p>
    </div>
    <p>
         Por fim, após completar o processo de busca, análise e armazenamento de palavras de sugestão, o sistema exibe os resultados no output.
    </p>
</section>
<section>
    <h2>🎞 Processamento</h2>
    <p>
        Durante o deselvovimento do algoritimo apresentado nesse repositório, foi-se utilizado de três principais tecnologias: Visual Studio Code e WSL:Ubunto.
    </p>
    <ul>
        <li>    
            <p>
                O Visual Studio Code é um editor de texto multiplataforma disponibilizado pela Microsoft para o desenvolvimento de aplicações, Conhecer essa ferramenta é importante para os desenvolvedores que pretendem trabalhar em ambientes multiplataforma, por exemplo,  podendo operar o desenvolvimento em ambiente Mac e Linux, ao mesmo tempo em que mantém o projeto compatível com Windows. Segue em anexo o link para o site da plataforma — <a href="https://code.visualstudio.com/" target="_blank">Visual Studio Code</a>.
            </p>
        </li>
        <li>
            <p>O WSL é um método para se executar o Sistema Operaciona Linux dentro do Windows de forma muito facil. Essa platoforma se torna essencial para o desenvovimento em ambiente GNU Linux, evitando tarefas como a intalação de maquinas vituais, criação de dual booting no computador pessoal e entre outras coisas. Além disso, existem diversas vantagens como rodar programas em conjunto e compartihamento de localhost. Segue em anexo um  tutorial de download do WSL2 — <a href="https://youtu.be/hd6lxt5iVsg" target="_blank">Tutorial WSL2</a>.</p>
        </li>
    </ul>
    <p>
        O programa ainda possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:
    </p>
    <div align="center">
        <table>
            <thead>
                <tr>
                    <th>Comando</th>
                    <th>Função</th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td><code>make clean</code></td>
                    <td>Apaga a última compilação realizada contida na pasta build</td>
                </tr>
                <tr>
                    <td><code>make</code></td>
                    <td>Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build</td>
                </tr>
                <tr>
                    <td><code>make run</code></td>
                    <td>Executa o programa da pasta build após a realização da compilação</td>
                </tr>
            </tbody>
        </table>
        <p align="center">
            <b>Tabela 1:</b> Comandos úteis para compilar e executar o programa de computador
        </p>
    </div>
</section>
<section>
    <hr size="0.5">
    <div>
          <p>
           Feito por <strong>Luan Gonçalves Santos</strong>     
         </p>
         <p align="right">
          <a href="https://www.linkedin.com/in/luan-santos-9bb01920b/" taget="_blank"><img src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"></a>
        <a href="https://www.instagram.com/luann_gsantos/" taget="_blank"><img src="https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white"></a>
        <p>
    </div>
</section>