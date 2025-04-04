NAME = libft.a # Name of the file that will be generated.

SRC = ft_atoi.c    \
       ft_bzero.c   \
       ft_calloc.c  \
       ft_isalnum.c \
       ft_isalpha.c \
       ft_isascii.c \
       ft_isdigit.c \
       ft_isprint.c \
       ft_memchr.c  \
       ft_memcmp.c  \
       ft_memcpy.c  \
       ft_memmove.c \
       ft_memset.c  \
       ft_putchar_fd.c \
       ft_putendl_fd.c \
       ft_putnbr_fd.c \
       ft_putstr_fd.c \
       ft_split.c  \
       ft_strchr.c \
       ft_strdup.c \
       ft_striteri.c \
       ft_strjoin.c \
       ft_strlcat.c \
       ft_strlcpy.c \
       ft_strlen.c \
       ft_strmapi.c \
       ft_strncmp.c \
       ft_strnstr.c \
       ft_strrchr.c \
       ft_strtrim.c \
       ft_substr.c \
       ft_tolower.c \
       ft_toupper.c \
       ft_itoa.c \
       get_next_line.c \
       ft_printf.c \
       ft_checkf.c \
       ft_putstr.c \
       ft_pointer_c.c \
       ft_putchar_c.c \
       ft_putnbr_base.c \
       ft_putstr_c.c \
       ft_putuint_c.c \
       ft_puthex_c.c \
       ft_putint_c.c
       

OBJS = $(SRC:.c=.o) # This variable will convert src .c files to object files .o

# These files will also be compiled if the bonus rule is executed.
BONUS = ft_lstadd_back.c  \
        ft_lstadd_front.c \
        ft_lstclear.c     \
        ft_lstdelone.c    \
        ft_lstiter.c      \
        ft_lstlast.c      \
        ft_lstmap.c       \
        ft_lstnew.c       \
        ft_lstsize.c

BONUS_OBJS = $(BONUS:.c=.o) # This will convert bonus .c files to bonus .o files

CC = gcc # Compiler that is going to be used
CFLAGS = -Wall -Werror -Wextra # Flags
RM = rm -rf # Command used to remove files or directories
AR = ar crs # Command used to create archives (static library)

# RULES

# In order to create the library libft.a all the object files must exist.
$(NAME): $(OBJS)
	$(AR) $@ $^ # This will create the archive. $@ represents the target ('libft.a)
	            # while '$^' represents all the .o files needed. 

%.o: %.c # Generic rule that specifies that every .c file must be compiled into a .o file
	$(CC) $(CFLAGS) -c $< -o $@ # This will compile every .c file into a .o file. $< is the source file, $@ is the object file.

all: $(NAME) # Default target. It will build libft.a. This is what will be executed if we just execute 'make'

clean: # This rule will delete all the .o files and bonus .o files. It won't erase $(NAME).
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) # Clean but also removes $(NAME).

re: fclean all # This will first execute fclean and then all. This will make sure everything will be compiled using new files, without using cached or old files.

bonus: $(OBJS) $(BONUS_OBJS) # This will compile OBJS and BONUS_OBJS and they will be added to libft.a.
	$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus # Without using .PHONY make can be tricked by the presence of files with the same names as the targets and decide not to run the targets. 
# With .PHONY make will always execute the targets, even if files with the same name exist, ensuring that commands will always be executed.
