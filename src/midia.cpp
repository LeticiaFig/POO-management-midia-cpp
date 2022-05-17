#include <iostream>
#include <algorithm>

#include "headers/musica.hpp"
#include "headers/filme.hpp"

#include <map>
#include <vector>
using namespace std;

template <typename T>
void printList(vector<T> objects, string midia)
{
  if (objects.size() == 0)
  {
    cout << "\nNenhum(a) " << midia << " para ser listado(a)\n";
    return;
  }
  cout << "___________________________________________\n"
       << "\tLista de " << midia << "s:\n\n"
       << "    Titulo - Ano de lancamento\n";
  for (size_t i = 0; i < objects.size(); i++)
    cout << "(" << i + 1 << ") " << objects[i].getTitulo() << " - " << objects[i].getAno() << "\n";
  cout << "___________________________________________\n";
}
void printArtistasList(vector<string> artistas, string midia)
{
  if (artistas.size() == 0)
  {
    cout << "\nNenhum artista do(a) " << midia << " para ser listado\n";
    return;
  }
  cout << "___________________________________________\n"
       << "\tLista de artistas do(a) " << midia << "s: \n\n";
  for (size_t i = 0; i < artistas.size(); i++)
    cout << "(" << i + 1 << ") " << artistas[i] << "\n";
  cout << "___________________________________________\n";
}
template <typename T>
void listArtistasByT(vector<T> objects, string midia)
{
  vector<string> artistas;
  for (size_t i = 0; i < objects.size(); i++)
  {
    vector<string> art = objects[i].getArtistas();
    artistas.insert(artistas.end(), art.begin(), art.end());
  }
  sort(artistas.begin(), artistas.end());
  artistas.erase(unique(artistas.begin(), artistas.end()), artistas.end());

  printArtistasList(artistas, midia);
}
template <typename T>
void listOrderByData(vector<T> objects, string midia, bool decrescente)
{
  if (decrescente)
    sort(objects.begin(), objects.end(), [](T &obj1, T &obj2)
         { return obj1.getData() > obj2.getData(); });
  else
    sort(objects.begin(), objects.end(), [](T &obj1, T &obj2)
         { return obj1.getData() < obj2.getData(); });
  printList<T>(objects, midia);
}
template <typename T>
void listByTitulo(vector<T> objects, string midia)
{
  sort(objects.begin(), objects.end(), [](T &obj1, T &obj2)
       { return obj1.getTitulo() < obj2.getTitulo(); });
  printList<T>(objects, midia);
}
template <typename T>
void listByData(vector<T> objects, int anoDeLancamento, string midia)
{
  vector<T> filteredObjectsByYear;
  copy_if(objects.begin(), objects.end(), back_inserter(filteredObjectsByYear), [&](T &obj)
          { return obj.getAno() == anoDeLancamento; });

  listByTitulo<T>(filteredObjectsByYear, midia);
}

void countMusicasByGenero(vector<Musica> musicas)
{
  map<GeneroDeMusica, int> counter;
  vector<GeneroDeMusica> generos;

  vector<string> generosDeMusica;
  generosDeMusica.push_back("Null_AudioGenre");
  generosDeMusica.push_back("Rock");
  generosDeMusica.push_back("Heavy_Metal");
  generosDeMusica.push_back("Eletronica");
  generosDeMusica.push_back("Blues");
  generosDeMusica.push_back("Jazz");
  generosDeMusica.push_back("Pop");
  generosDeMusica.push_back("Samb");

  for (size_t i = 0; i < musicas.size(); i++)
  {
    generos = musicas[i].getGeneroDeMusica();
    for_each(begin(generos), end(generos), [&](GeneroDeMusica const &s)
             { ++counter[s]; });
  }

  cout << endl
       << "Contagem de g�neros musicais" << endl
       << endl;
  for (auto const &pair : counter)
  {
    cout << generosDeMusica[pair.first] << ": " << pair.second << endl;
  }
}

void countFilmesByGenero(vector<Filme> filmes)
{
  map<GenerosDeFilme, int> counter;
  vector<GenerosDeFilme> generos;

  vector<string> generoDeFilme;
  generoDeFilme.push_back("Null_MovieGenre");
  generoDeFilme.push_back("Terror");
  generoDeFilme.push_back("Suspense");
  generoDeFilme.push_back("Acao");
  generoDeFilme.push_back("Drama");
  generoDeFilme.push_back("Documentario");
  generoDeFilme.push_back("Comedia");

  for (size_t i = 0; i < filmes.size(); i++)
  {
    generos = filmes[i].getGeneroDeFilme();
    for_each(begin(generos), end(generos), [&](GenerosDeFilme const &s)
             { ++counter[s]; });
  }

  cout << endl
       << "Contagem de g�neros de filmes" << endl
       << endl;
  for (auto const &pair : counter)
  {
    cout << generoDeFilme[pair.first] << ": " << pair.second << endl;
  }
}

void listAllByTitulo(vector<Filme> filmes, vector<Musica> musicas)
{
  listByTitulo<Musica>(musicas, "musica");
  listByTitulo<Filme>(filmes, "filme");
}

void listAllByData(vector<Filme> filmes, vector<Musica> musicas, int anoDeLancamento)
{
  listByData<Musica>(musicas, anoDeLancamento, "musica");
  listByData<Filme>(filmes, anoDeLancamento, "filme");
}

void listAllArtistas(vector<Filme> filmes, vector<Musica> musicas)
{
  listArtistasByT<Musica>(musicas, "musica");
  listArtistasByT<Filme>(filmes, "filme");
}

void remocaoMidia()
{
  listOrderByData<Filme>(filmes, "filme", true);
  listOrderByData<Musica>(musicas, "musica", true);

  int midiaType = promptMidiaType();
  int midiaToRemove = promptRemoveMidia();

  // todo: alterar a função para retornar decrescente
  switch (midiaType)
  {
  case '1':
    if (midiaToRemove > 0 && midiaToRemove < filmes.size())
    {
      cout << "O filme selecionado é inválido. Por favor, tente novamente!";
      break;
    }
    filmes.erase(filmes.begin() + midiaToRemove - 1);
    cout << "Filme " << midiaToRemove << " removido com sucesso!";

    break;

  case '2':
    if (midiaToRemove > 0 && midiaToRemove < filmes.size())
    {
      cout << "A música selecionada é inválida. Por favor, tente novamente!";
      break;
    }
    musicas.erase(musicas.begin() + midiaToRemove - 1);
    cout << "Música " << midiaToRemove << " removida com sucesso!";

    break;

  default:
    break;
  }
}