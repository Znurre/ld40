SOURCES += \
    main.cpp \
    Window.cpp \
    World.cpp \
    Map.cpp \
    MapLoader.cpp \
    MapTile.cpp \
    Player.cpp \
    InputHandler.cpp \
    TurnHandler.cpp \
    Enemy.cpp \
    CollisionHandler.cpp \
    Shard.cpp

HEADERS += \
    Window.h \
    World.h \
    IDrawable.h \
    Map.h \
    MapLoader.h \
    MapTile.h \
    Player.h \
    InputHandler.h \
    TurnHandler.h \
    IPawn.h \
    Enemy.h \
    CollisionHandler.h \
    Shard.h

LIBS += -ltiled
