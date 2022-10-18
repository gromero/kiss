# Introduction

The code in this repo is meant to preprocess signed PCM-24 samples into MFCCs
(mel-log filterbank cepstral coeficients) and generate a proper spectrogram for
utterances feeding the `keyword spotting` AI model taken from the `MLPerf Tiny`
benchmark.

This code can be tested against a "yes" utterence the following way:

```sh
$ make run FILE=yes_from_board_v2.raw
```

and the result will be:

```
spectrogram_tensor[49][10] = {
{ -128,   83,   83,   83,   83,   83,   83,   83,   83,   83 },
{ -128,   83,   83,   83,   83,   83,   83,   83,   83,   83 },
{   23,   90,   84,   83,   84,   83,   81,   82,   83,   84 },
{   18,   89,   84,   83,   84,   83,   83,   81,   82,   82 },
{   20,   89,   84,   82,   84,   82,   82,   82,   83,   83 },
{   20,   88,   82,   82,   81,   80,   80,   82,   83,   82 },
{   19,   89,   81,   83,   85,   84,   83,   84,   84,   83 },
{   20,   90,   82,   83,   85,   83,   80,   82,   82,   83 },
{   18,   89,   81,   83,   85,   83,   81,   81,   81,   82 },
{   19,   89,   83,   83,   84,   83,   82,   83,   82,   82 },
{   17,   90,   84,   82,   84,   82,   81,   84,   85,   83 },
{   55,   94,   88,   79,   80,   79,   82,   78,   82,   81 },
{   45,   95,   86,   78,   81,   81,   82,   77,   81,   80 },
{   44,   96,   86,   78,   81,   81,   80,   76,   80,   82 },
{   47,   93,   88,   81,   81,   82,   79,   79,   83,   81 },
{   52,   87,   91,   84,   79,   83,   80,   78,   83,   81 },
{   46,   88,   92,   80,   81,   82,   78,   80,   80,   81 },
{   47,   88,   94,   81,   83,   80,   81,   79,   82,   81 },
{   45,   91,   96,   80,   84,   82,   80,   79,   83,   80 },
{   51,   88,   97,   81,   82,   82,   81,   80,   81,   80 },
{   61,   85,   98,   82,   80,   81,   81,   81,   81,   80 },
{   70,   83,   99,   82,   78,   81,   82,   80,   79,   80 },
{   84,   81,   96,   81,   75,   79,   81,   79,   81,   81 },
{   91,   81,   91,   79,   73,   78,   81,   79,   82,   83 },
{  101,   80,   88,   78,   73,   80,   84,   81,   82,   82 },
{  104,   77,   86,   78,   75,   81,   85,   80,   80,   80 },
{  112,   80,   86,   80,   78,   82,   87,   82,   82,   81 },
{  111,   78,   82,   78,   77,   81,   87,   81,   80,   81 },
{  112,   76,   80,   77,   77,   80,   87,   79,   79,   80 },
{  113,   77,   79,   79,   78,   80,   86,   79,   80,   79 },
{  112,   77,   79,   79,   78,   80,   86,   80,   79,   79 },
{  106,   78,   78,   78,   77,   80,   85,   81,   78,   79 },
{  103,   80,   81,   79,   78,   80,   86,   81,   79,   79 },
{   86,   86,   81,   80,   79,   80,   83,   81,   81,   79 },
{   78,   84,   81,   80,   79,   80,   86,   82,   81,   81 },
{   73,   84,   83,   80,   81,   80,   85,   80,   81,   80 },
{   74,   82,   84,   78,   81,   80,   85,   80,   81,   81 },
{   73,   79,   85,   77,   81,   79,   86,   79,   81,   81 },
{   67,   81,   85,   78,   82,   80,   84,   80,   81,   80 },
{   63,   76,   83,   79,   83,   79,   85,   81,   79,   81 },
{   61,   76,   84,   80,   84,   81,   87,   82,   84,   82 },
{   59,   78,   86,   79,   82,   78,   86,   82,   79,   81 },
{   58,   79,   86,   78,   83,   80,   86,   82,   82,   82 },
{   56,   77,   85,   81,   84,   80,   85,   82,   84,   81 },
{   54,   77,   86,   79,   84,   81,   84,   82,   82,   82 },
{   57,   78,   86,   80,   84,   80,   85,   81,   82,   82 },
{   52,   77,   87,   81,   83,   79,   85,   82,   83,   82 },
{   54,   78,   88,   81,   84,   81,   86,   83,   81,   81 },
{   50,   79,   89,   79,   84,   80,   85,   80,   80,   81 },
};
```
