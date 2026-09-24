# xhair-overlay

Renders a literal `+` text in the center of the screen to use as a crosshair using [`gtk4-layer-shell`](https://github.com/wmww/gtk4-layer-shell) \
This also means it's wayland only.

## build

### dependencies
- `gtk4`
- [`gtk4-layer-shell`](https://github.com/wmww/gtk4-layer-shell)

### compile

```
meson setup build
meson compile -C build
```
