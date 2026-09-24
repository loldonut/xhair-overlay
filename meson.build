project(
  'xhair-overlay',
  'c',
  meson_version : '>= 1.3.0',
  version : '0.1',
  default_options : ['warning_level=3'],
)

dependencies = [
  dependency('gtk4-layer-shell-0'),
  dependency('gtk4')
]

sources = [
  'main.c',
]

executable(
  'xhair-overlay',
  sources,
  dependencies : dependencies,
  install : true,
)
