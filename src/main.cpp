#include <iostream>

#include "midia.cpp"
#include "musica.cpp"
#include "filme.cpp"

#include <vector>
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
vector<string> promptArtistas()
{
  bool flag = true;
  string artista;
  vector<string> artistas;
  while (flag)
  {
    cout << "Digite o nome do artista do(a) filme/musica: ";
    cin >> artista;
    artistas.push_back(artista);
    flag = promptYesOrNo("H� mais outro artista? (s/n): ");
  }
  return artistas;
}
string promptTitulo()
{
  string titulo;
  cout << "Digite o titulo do(a) filme/musica: ";
  cin >> titulo;
  return titulo;
}
int promptData()
{
  int data;
  cout << "Digite a data quando foi feito o(a) filme/musica (formato: 03/05/2022 = 3052022): "; // todo acho q pelo enunciado as vezes isso aki � so o ano de lan�amento q ele qr
  cin >> data;
  return data;
}
int promptDuracao()
{
  int duracao;
  cout << "Digite a duracao do(a) filme/musica (em segundos): ";
  cin >> duracao;
  return duracao;
}
vector<string> promptKeywords()
{
  bool flag = true;
  string keyword;
  vector<string> keywords;
  while (flag)
  {
    cout << "Digite a keyword que voc� gostaria de associar a(o) filme/musica: ";
    cin >> keyword;
    keywords.push_back(keyword);
    flag = promptYesOrNo("H� mais outra keyword? (s/n): ");
  }
  return keywords;
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
  GeneroDeMusica genero;
  vector<GeneroDeMusica> generos;
  while (flag)
  {
    string tmp;
    cout << "Digite o genero da musica: ";
    cin >> tmp;
    genero = stringToGeneroDeMusica(tmp);
    if (genero == GeneroDeMusica::Null_AudioGenre) // todo mandar feedback q digitou errado
      continue;
    generos.push_back(genero);
    flag = promptYesOrNo("H� mais outro genero? (s/n): ");
  }
  return generos;
}

vector<GenerosDeFilme> promptGeneroDeFilme()
{
  bool flag = true;
  GenerosDeFilme genero;
  vector<GenerosDeFilme> generos;
  while (flag)
  {
    string tmp;
    cout << "Digite o genero do filme: ";
    cin >> tmp;
    genero = stringToGeneroDeFilme(tmp);
    if (genero == GenerosDeFilme::Null_MovieGenre) // todo mandar feedback q digitou errado
      continue;
    generos.push_back(genero);
    flag = promptYesOrNo("H� mais outro genero? (s/n): ");
  }
  return generos;
}

vector<FormatoDeAudio> promptFormatoDeAudio()
{
  bool flag = true;
  FormatoDeAudio audio;
  vector<FormatoDeAudio> audios;
  while (flag)
  {
    string tmp;
    cout << "Digite o formato de audio desta musica: ";
    cin >> tmp;
    audio = stringToFormatoDeAudio(tmp);
    if (audio == FormatoDeAudio::Null_AudioFormat) // todo mandar feedback q digitou errado
      continue;
    audios.push_back(audio);
    flag = promptYesOrNo("H� mais outro formato de audio? (s/n): ");
  }
  return audios;
}
vector<FormatosDeVideo> promptFormatoDeVideo()
{
  bool flag = true;
  FormatosDeVideo video;
  vector<FormatosDeVideo> videos;
  while (flag)
  {
    string tmp;
    cout << "Digite o formato de video deste filme: ";
    cin >> tmp;
    video = stringToFormatoDeVideo(tmp);
    if (video == FormatosDeVideo::Null_VideoFormat) // todo mandar feedback q digitou errado
      continue;
    videos.push_back(video);
    flag = promptYesOrNo("H� mais outro formato de video? (s/n): ");
  }
  return videos;
}

int promptAnoDeLancamento()
{
  int anoDeLancamento;
  cout << "Digite o ano de lançamento que deseja buscar: ";
  cin >> anoDeLancamento;
  return anoDeLancamento;
}

void remocaoMidia()
{
}
void tela4()
{
  char acao;
  while (true)
  {
    cout << endl
         << "(1) Listagem Completa\n"
         << "(2) Listagem de m�sicas\n"
         << "(3) Listagem de filmes\n"
         << "(4) Listagem por data\n"
         << "(5) Listagem de artistas\n"
         << "(6) Contagem de musicas por genero\n"
         << "(7) Contagem de filmes por genero\n"
         << "(8) Voltar\n";
    cin >> acao;

    // Dados para teste

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

    switch (acao)
    {
    case '1':
      listAllByTitulo(filmes, musicas);
      break;

    case '2':
      listMusicasOrderByData(musicas);
      break;

    case '3':
      listFilmesOrderByData(filmes);
      break;

    case '4':
      int anoDeLancamento;
      anoDeLancamento = promptAnoDeLancamento();
      listAllByData(filmes, musicas, anoDeLancamento);
      break;

    case '5':
      listAllArtistas(filmes, musicas);
      break;

    case '6':
      countMusicasByGenero(musicas);
      break;

    case '7':
      countFilmesByGenero(filmes);
      break;

    default:
      break;
    }
  }
}

void tela5()
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
      // todo escolha aleatoria de filme
    }
    else if (acao == '2')
    {
      // todo criacao de playlist de musica
    }
    else if (acao == '3')
    {
      // todo busca por keyword
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
void tela2()
{
  char acao;
  while (true)
  {
    cout << "(1) Cadastro de novas m�dias\n"
         << "(2) Remo��o de m�dias existentes\n"
         << "(3) Voltar\n";
    cin >> acao;
    if (acao == '3')
      break;
    else if (acao == '1')
      cadastroMidia();
    else if (acao == '2')
      remocaoMidia();
  }
}
void tela3()
{
  char acao;
  while (true)
  {
    cout << "(1) Pesquisa de m�dias\n"
         << "(2) Sugest�o de m�dias\n"
         << "(3) Voltar\n";
    cin >> acao;
    if (acao == '3')
      break;
    else if (acao == '1')
      tela4();
    else if (acao == '2')
      tela5();
  }
}
void telaInicial()
{
  char acao;
  while (true)
  {
    cout << "(1) Cadastro/Remo��o de m�dias\n"
         << "(2) Pesquisa/Sugest�o de m�dias\n"
         << "(3) Sair\n";
    cin >> acao;
    if (acao == '3')
      break;
    else if (acao == '1')
      tela2();
    else if (acao == '2')
      tela3();
  }
}

int main()
{
  cout << "Bem-vindo ao nosso Sistema de Gerenciamento de M�dias\n";
  telaInicial();
  return 0;
};