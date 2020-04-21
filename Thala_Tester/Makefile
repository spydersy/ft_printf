NAME = test_printf

SRC = main.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Wextra -W -Werror -fno-builtin -Wno-format -Wno-format-extra-args
LDFLAGS += -L. -lftprintf

$(NAME):
	gcc $(CFLAGS) -o system_printf main.c
	gcc $(CFLAGS) -D_FT_USER__ -o user_printf main.c $(LDFLAGS)
	./system_printf > SYSOUT
	./user_printf > USEROUT

all: $(NAME)

clean:
	rm -rf main.o

fclean: clean
	rm -rf system_printf
	rm -rf user_printf

rebuild: distclean $(NAME)
