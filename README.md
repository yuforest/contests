## コンパイルを行うためのコマンド
```
g++ -o main.out main.cpp -O2 -I /Users/yuforest/dev/ac-library/debug -I /Users/yuforest/dev/ac-library/ac-library -D LOCAL
```

- O2は最適化オプションでこれがないとエラーになる様子
- -Iは含めるファイルを記載、debugとatcoderのライブラリを含めている
- main.outで出力