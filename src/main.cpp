#include <iostream>

#include "midia.cpp"
#include "musica.cpp"
#include "filme.cpp"

#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<Musica> musicas;
vector<Filme> filmes;

bool promptYesOrNo(string str)
{
  char acao;
  while (true)
  {
    cout << str;
    cin >> acao;
    if (acao == 's' || acao == 'S' || acao == 'n' || acao == 'N')
    {
      if (acao != 's' && acao != 'S')
        return false;
      return true;
    }
  }
}
template <typename T>
T promptObject(string str)
{
  T object;
  cout << str;
  cin >> object;
  return object;
}
template <typename T>
vector<T> promptObjects(string str, string str2)
{
  bool flag = true;
  vector<T> objects;
  while (flag)
  {
    objects.push_back(promptObject<T>(str));
    flag = promptYesOrNo(str2);
  }
  return objects;
}
string promptTitulo()
{
  return promptObject<string>("Digite o titulo do(a) filme/musica: ");
}
int promptData()
{
  return promptObject<int>("Digite a data quando foi feito o(a) filme/musica (formato: 03/05/2022 = 3052022): ");
}
int promptAnoDeLancamento()
{
  return promptObject<int>("Digite o ano de lançamento que deseja buscar: ");
}
int promptDuracao()
{
  return promptObject<int>("Digite a duracao do(a) filme/musica (em segundos): ");
}
vector<string> promptKeywords()
{
  return promptObjects<string>("Digite a keyword que voce gostaria de associar a(o) filme/musica: ", "Ha mais outra keyword? (s/n): ");
}
vector<string> promptArtistas()
{
  return promptObjects<string>("Digite o nome do artista do(a) filme/musica: ", "Ha mais outro artista? (s/n): ");
}

int promptMidiaType()
{
  return promptObject<int>("Digite qual o tipo de mídia que deseja remover: \n\n(1)Filme \n(2)Música \n(3)Voltar");
}

int promptRemoveMidia()
{
  return promptObject<int>("Selecione o número da lista acima correspondente à mídia que deseja remover ou 0(zero) para cancelar a operação: ");
}

FormatoDeAudio stringToFormatoDeAudio(string str)
{
  if (str == "mp3")
    return FormatoDeAudio::mp3;
  else if (str == "AAC")
    return FormatoDeAudio::AAC;
  else if (str == "OGG")
    return FormatoDeAudio::OGG;
  else if (str == "WMA")
    return FormatoDeAudio::WMA;
  return FormatoDeAudio::Null_AudioFormat;
}
FormatosDeVideo stringToFormatoDeVideo(string str)
{
  if (str == "AVI")
    return FormatosDeVideo::AVI;
  else if (str == "MKV")
    return FormatosDeVideo::MKV;
  else if (str == "MP4")
    return FormatosDeVideo::MP4;
  else if (str == "FLV")
    return FormatosDeVideo::FLV;
  return FormatosDeVideo::Null_VideoFormat;
}
GeneroDeMusica stringToGeneroDeMusica(string str)
{
  if (str == "Rock")
    return GeneroDeMusica::Rock;
  else if (str == "Heavy Metal")
    return GeneroDeMusica::Heavy_Metal;
  else if (str == "Eletronica")
    return GeneroDeMusica::Eletronica;
  else if (str == "Blues")
    return GeneroDeMusica::Blues;
  else if (str == "Jazz")
    return GeneroDeMusica::Jazz;
  else if (str == "Pop")
    return GeneroDeMusica::Pop;
  else if (str == "Samba")
    return GeneroDeMusica::Samba;
  return GeneroDeMusica::Null_AudioGenre;
}
GenerosDeFilme stringToGeneroDeFilme(string str)
{
  if (str == "Terror")
    return GenerosDeFilme::Terror;
  else if (str == "Suspense")
    return GenerosDeFilme::Suspense;
  else if (str == "Acao")
    return GenerosDeFilme::Acao;
  else if (str == "Drama")
    return GenerosDeFilme::Drama;
  else if (str == "Documentario")
    return GenerosDeFilme::Documentario;
  else if (str == "Comedia")
    return GenerosDeFilme::Comedia;
  return GenerosDeFilme::Null_MovieGenre;
}

vector<GeneroDeMusica> promptGeneroDeMusica()
{
  bool flag = true;
  vector<GeneroDeMusica> generos;
  while (flag)
  {
    GeneroDeMusica genero;
    genero = stringToGeneroDeMusica(promptObject<string>("Digite o genero da musica: "));
    if (genero == GeneroDeMusica::Null_AudioGenre)
    {
      cout << "Genero invalido\n";
      continue;
    }
    generos.push_back(genero);
    flag = promptYesOrNo("Ha mais outro genero? (s/n): ");
  }
  return generos;
}

vector<GenerosDeFilme> promptGeneroDeFilme()
{
  bool flag = true;
  vector<GenerosDeFilme> generos;
  while (flag)
  {
    GenerosDeFilme genero;
    genero = stringToGeneroDeFilme(promptObject<string>("Digite o genero do filme: "));
    if (genero == GenerosDeFilme::Null_MovieGenre)
    {
      cout << "Genero invalido\n";
      continue;
    }
    generos.push_back(genero);
    flag = promptYesOrNo("Ha mais outro genero? (s/n): ");
  }
  return generos;
}

vector<FormatoDeAudio> promptFormatoDeAudio()
{
  bool flag = true;
  vector<FormatoDeAudio> audios;
  while (flag)
  {
    FormatoDeAudio audio;
    audio = stringToFormatoDeAudio(promptObject<string>("Digite o formato de audio desta musica: "));
    if (audio == FormatoDeAudio::Null_AudioFormat)
    {
      cout << "Formato invalido\n";
      continue;
    }
    audios.push_back(audio);
    flag = promptYesOrNo("Ha mais outro formato de audio? (s/n): ");
  }
  return audios;
}
vector<FormatosDeVideo> promptFormatoDeVideo()
{
  bool flag = true;
  vector<FormatosDeVideo> videos;
  while (flag)
  {
    FormatosDeVideo video;
    video = stringToFormatoDeVideo(promptObject<string>("Digite o formato de video deste filme: "));
    if (video == FormatosDeVideo::Null_VideoFormat)
    {
      cout << "Formato invalido\n";
      continue;
    }
    videos.push_back(video);
    flag = promptYesOrNo("Ha mais outro formato de video? (s/n): ");
  }
  return videos;
}

void remocaoMidia()
{

  vector<GeneroDeMusica> generoDeMusica;
  vector<GeneroDeMusica> generoDeMusica1;
  vector<FormatoDeAudio> formatoDeAudio;
  vector<GenerosDeFilme> generoDeFilme;
  vector<FormatosDeVideo> formatoDeVideo;
  vector<string> artistas;
  vector<string> keywords;
  artistas.push_back("c");
  artistas.push_back("a");
  artistas.push_back("b");
  generoDeMusica.push_back(Rock);
  generoDeMusica.push_back(Heavy_Metal);
  generoDeMusica1.push_back(Heavy_Metal);
  generoDeMusica1.push_back(Blues);
  musicas.push_back(Musica(formatoDeAudio, generoDeMusica1, "Title", artistas, 123, 0, keywords, 0));
  musicas.push_back(Musica(formatoDeAudio, generoDeMusica, "ATitle", artistas, 123, 0, keywords, 0));
  filmes.push_back(Filme(formatoDeVideo, generoDeFilme, "ATitle", artistas, 123, 0, keywords, 0));

  listFilmesOrderByData(filmes);
  listMusicasOrderByData(musicas);

  int midiaType = promptMidiaType();
  int midiaToRemove = promptRemoveMidia();

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
         << "(8) Voltar\n";
    cin >> acao;

    if (acao == '8')
      break;
    else if (acao == '1')
      listAllByTitulo(filmes, musicas); // 2.1 - Listagem completa
    else if (acao == '2')
      listMusicasOrderByData(musicas); // 2.2 - Listagem de musicas
    else if (acao == '3')
      listFilmesOrderByData(filmes); // 2.3 - Listagem de filmes
    else if (acao == '4')
      listAllByData(filmes, musicas, promptAnoDeLancamento()); // 2.4 - Listagem por data
    else if (acao == '5')
      listAllArtistas(filmes, musicas); // 2.5 - Listagem de Artistas
    else if (acao == '6')
      countMusicasByGenero(musicas); // 2.6 - Contagem de musicas por genero
    else if (acao == '7')
      countFilmesByGenero(filmes); // 2.7 - Contagem de filmes por genero
  }
}

void tela3()
{
  char acao;
  while (true)
  {
    cout << "(1) Escolha aleatoria de filme\n"
         << "(2) Criacao de playlist de musicas\n"
         << "(3) Busca por \'keyword\' \n"
         << "(4) Voltar\n";
    cin >> acao;
    if (acao == '4')
      break;
    else if (acao == '1')
    {
      // todo 2.8 - Escolha aleatoria de filme
    }
    else if (acao == '2')
    {
      // todo 2.9 - Criacao de playlist de musicas
    }
    else if (acao == '3')
    {
      // todo 2.10 - Busca por keyword
    }
  }
}
void cadastroMidia()
{
  char acao;
  while (true)
  {
    cout << "(1) Cadastro de musica\n"
         << "(2) Cadastro de filme\n"
         << "(3) Voltar\n";
    cin >> acao;
    if (acao == '3')
      break;
    else if (acao == '1')
      musicas.push_back(Musica(promptFormatoDeAudio(), promptGeneroDeMusica(), promptTitulo(), promptArtistas(), promptData(), promptDuracao(), promptKeywords(), 0));
    else if (acao == '2')
      filmes.push_back(Filme(promptFormatoDeVideo(), promptGeneroDeFilme(), promptTitulo(), promptArtistas(), promptData(), promptDuracao(), promptKeywords(), 0));
  }
}
void telaInicial()
{
  char acao;
  while (true)
  {
    cout << "(1) Cadastro de novas midias\n"
         << "(2) Remocao de midias existentes\n"
         << "(3) Pesquisa de midias\n"
         << "(4) Sugestao de midias\n"
         << "(5) Sair\n";
    cin >> acao;
    if (acao == '5')
      break;
    else if (acao == '1')
      cadastroMidia(); // 1.1 - Cadastro
    else if (acao == '2')
      remocaoMidia(); // 1.2 - Remoção
    else if (acao == '3')
      tela2();
    else if (acao == '4')
      tela3();
  }
}

int main()
{
  cout << "Bem-vindo ao nosso Sistema de Gerenciamento de Midias\n\n";
  telaInicial();
  return 0;
};