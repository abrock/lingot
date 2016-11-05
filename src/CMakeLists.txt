cmake_minimum_required(VERSION 3.6)

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "/usr/lib/x86_64-linux-gnu/cmake/KF5KDELibs4Support/")

find_package(GTK REQUIRED)

include_directories(${GTK_INCLUDE_DIR})
include_directories("/usr/include/gtk-3.0")

set(GLIB2_DIR ".")
find_package(GLIB2 REQUIRED)
include_directories(${GLIB2_INCLUDE_DIR})

set(PANGO_DIR ".")
find_package(PANGO REQUIRED)
include_directories(${Pango_1_0_INCLUDE_DIR})

set(CAIRO_DIR ".")
find_package(CAIRO REQUIRED)
include_directories(${CAIRO_INCLUDE_DIRS})

include_directories("/usr/include/gdk-pixbuf-2.0")

set(ATK_DIR ".")
find_package(ATK REQUIRED)
include_directories(${ATK_INCLUDE_DIRS})

set (CMAKE_C_FLAGS "-DLINGOT_GLADEDIR=\\\"/usr/local/share/lingot/glade/\\\" -DLINGOT_LOCALEDIR=\\\"/usr/local/share/locale\\\" -g -O2 -DOSS -DALSA -DJACK -DPULSEAUDIO -DLIBFFTW")

add_executable(lingot lingot.c)

set(ownlibs
  lingot-fft
  lingot-audio
  lingot-audio-oss
  lingot-audio-alsa
  lingot-audio-jack
  lingot-audio-pulseaudio
  lingot-complex
  lingot-config
  lingot-config-scale
  lingot-core
  lingot-msg
  lingot-gui-config-dialog
  lingot-gui-config-dialog-scale
  lingot-gauge
  lingot-filter
  lingot-signal
  lingot-gui-mainframe)

foreach (lib ${ownlibs})
  add_library(${lib} ${lib}.c)
  target_link_libraries(lingot ${lib})
endforeach()

foreach (lib ${ownlibs})
  if (NOT ${lib} MATCHES "lingot-gui-mainframe")
    target_link_libraries(lingot-gui-mainframe ${lib})
  endif()
  if (NOT ${lib} MATCHES "lingot-core")
    target_link_libraries(lingot-core ${lib})
  endif()
endforeach()

target_link_libraries(lingot-filter lingot-complex)


#target_link_libraries(lingot-config lingot-config-scale)
target_link_libraries(lingot-gui-mainframe ${GLIB2_LIBRARIES})
target_link_libraries(lingot-gui-mainframe ${GTK_LIBRARIES})
target_link_libraries(lingot-gui-mainframe "glib-2.0")
target_link_libraries(lingot-gui-mainframe "gdk-3")

foreach (lib
    gtk-3
    gdk-3
    pangocairo-1.0
    pango-1.0
    atk-1.0
    cairo-gobject
    cairo
    gdk_pixbuf-2.0
    gio-2.0
    gobject-2.0
    glib-2.0
    asound
    jack
    pulse-simple
    pulse
    fftw3
    fftw3f
    pthread
    m)
  target_link_libraries(lingot ${lib})
endforeach()

target_link_libraries(lingot
  m
  ${ATK_LIBRARIES}
  ${CAIRO_LIBRARIES}
  ${GLIB2_LIBRARIES}
  ${GTK_LIBRARIES}
  ${Pango_1_0_LIBRARIES}
  ${GTK_LIBRARIES})

