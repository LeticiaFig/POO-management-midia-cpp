#ifndef Prompt_CPP
#define Prompt_CPP

#include <iostream>
#include <vector>

#include "filme.cpp"
#include "musica.cpp"

using namespace std;

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

int promptMidiaType()
{
  return promptObject<int>("Digite qual o tipo de mídia que deseja remover: \n\n(1)Filme \n(2)Música \n(3)Voltar");
}

int promptRemoveMidia()
{
  return promptObject<int>("Selecione o número da lista acima correspondente à mídia que deseja remover ou 0(zero) para cancelar a operação: ");
}

#endif