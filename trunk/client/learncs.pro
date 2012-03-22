HEADERS       = window.h
SOURCES       = main.cpp \
                window.cpp
RESOURCES     = learncs.qrc
QT           += xml svg

# install
target.path = $$[QT_INSTALL_EXAMPLES]/desktop/learncs
sources.files = $$SOURCES $$HEADERS $$RESOURCES $$FORMS learncs.pro resources images
sources.path = $$[QT_INSTALL_EXAMPLES]/desktop/learncs
INSTALLS += target sources

symbian: include($$QT_SOURCE_TREE/examples/symbianpkgrules.pri)

wince* {
	CONFIG(debug, release|debug) {
		addPlugins.sources = $$QT_BUILD_TREE/plugins/imageformats/qsvgd4.dll
	}
	CONFIG(release, release|debug) {
		addPlugins.sources = $$QT_BUILD_TREE/plugins/imageformats/qsvg4.dll
	}
	addPlugins.path = imageformats
	DEPLOYMENT += addPlugins
}
