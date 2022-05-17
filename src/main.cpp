#include <iostream>

#include "midia.cpp"
#include "musica.cpp"
#include "filme.cpp"

#include "prompt.cpp"

#include <vector>
using namespace std;

vector<Musica> musicas;
vector<Filme> filmes;

void tela2()
{
  char acao;
  while (true)
  {
    cout << endl
         << "(1) Listagem Completa\n"
         << "(2) Listagem de musicas\n"
         << "(3) Listagem de filmes\n"
         << "(4) Listagem por data\n"
         << "(5) Listagem de artistas\n"
         << "(6) Contagem de musicas por genero\n"
         << "(7) Contagem de filmes por genero\n"
         << "(8) Voltar\n\n";
    cin >> acao;

    if (acao == '1')
      listAllByTitulo(filmes, musicas); // 2.1 - Listagem completa
    else if (acao == '2')
      listOrderByData<Musica>(musicas, "musica", false); // 2.2 - Listagem de musicas
    else if (acao == '3')
      listOrderByData<Filme>(filmes, "filme", false); // 2.3 - Listagem de filmes
    else if (acao == '4')
      listAllByData(filmes, musicas, promptAnoDeLancamento()); // 2.4 - Listagem por data
    else if (acao == '5')
      listAllArtistas(filmes, musicas); // 2.5 - Listagem de Artistas
    else if (acao == '6')
      countMusicasByGenero(musicas); // 2.6 - Contagem de musicas por genero
    else if (acao == '7')
      countFilmesByGenero(filmes); // 2.7 - Contagem de filmes por genero
    else if (acao == '8')
      break;
  }
}

void tela3()
{
  char acao;
  while (true)
  {
    cout << "(1) Escolha aleatória de filme\n"
         << "(2) Criacao de playlist de músicas\n"
         << "(3) Busca por \'keyword\' \n"
         << "(4) Voltar\n\n";
    cin >> acao;

    if (acao == '1')
    {
      chooseRandomFilme(filmes); // 2.8 - Escolha aleatória de filme
    }
    else if (acao == '2')
    {
      // todo 2.9 - Criacao de playlist de musicas
    }
    else if (acao == '3')
    {
      // todo 2.10 - Busca por keyword
    }
    else if (acao == '4')
      break;
  }
}

void telaInicial()
{
  char acao;
  while (true)
  {
    cout << "(1) Cadastro de novas mídias\n"
         << "(2) Remoção de mídias existentes\n"
         << "(3) Pesquisa de mídias\n"
         << "(4) Sugestão de mídias\n"
         << "(5) Sair\n\n";

    cin >> acao;
    if (acao == '5')
      break;
    else if (acao == '1')
      cadastroMidia(filmes, musicas); // 1.1 - Cadastro
    else if (acao == '2')
    {
      listAllOrderByData(filmes, musicas, true);
      int midiaType = promptMidiaType();
      int midiaToRemove = promptRemoveMidia();
      remocaoMidia(filmes, musicas, midiaType, midiaToRemove); // 1.2 - Remoção de mídias
    }
    else if (acao == '3')
      tela2();
    else if (acao == '4')
      tela3();
  }
}

int main()
{
  cout << "Bem-vindo ao nosso Sistema de Gerenciamento de Mídias\n\n";
  telaInicial();
  return 0;
};