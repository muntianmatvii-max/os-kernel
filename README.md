# OS Kernel x86_64

Простое ядро операційної системи, написане на C для архітектури x86_64.

## Особливості

- **Bootloader**: GRUB-сумісний bootloader
- **Memory Management**: Базова система керування пам'яттю з malloc/free
- **File System**: Простая файлова система з підтримкою файлів і директорій
- **Console**: VGA текстовий вивід

## Структура проекту

```
os-kernel/
├── src/
│   ├── boot/           # Bootloader код (Assembly)
│   ├── console/        # Консоль (VGA text mode)
│   ├── memory/         # Управління пам'яттю
│   ├── filesystem/     # Файлова система
│   ├── kernel.c        # Основна функція ядра
│   └── kernel.h        # Загальні типи і макроси
├── Makefile            # Build файл
├── linker.ld           # Linker скрипт
├── grub.cfg            # GRUB конфігурація
└── README.md           # Цей файл
```

## Збірка

```bash
make          # Збирати ядро
make iso      # Створити ISO образ
make clean    # Очистити build артефакти
make rebuild  # Очистити та перебудувати
```

## Вимоги

- `gcc` - C компілятор
- `nasm` - Assembler
- `ld` - Linker
- `grub-mkrescue` - для створення ISO
- `xorriso` - для мастерування ISO

## Запуск

Для запуску в емуляторі:

```bash
qemu-system-x86_64 -cdrom kernel.iso
```

## Подальший розвиток

- [ ] Interrupt handling (IDT, ISR, IRQ)
- [ ] Process/Thread management
- [ ] Paging і virtual memory
- [ ] Disk I/O
- [ ] More advanced file system (ext2, FAT32)
- [ ] Shell/CLI
- [ ] Network stack

## Автор

muntianmatvii-max
