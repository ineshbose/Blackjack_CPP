project('blackjack', 'cpp', default_options: ['cpp_std=c++14'])

main_target_name = 'blackjack'
sources = ['src/blackjack.cpp', 'src/card.cpp', 'src/dealer.cpp', 'src/deck.cpp', 'src/game.cpp', 'src/human.cpp', 'src/player.cpp', 'src/print.cpp', 'src/statistics.cpp']
hdrs = include_directories('src/headers')

executable(main_target_name, sources, include_directories: hdrs, install: true)