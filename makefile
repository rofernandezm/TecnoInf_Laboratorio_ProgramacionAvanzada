# === Compilador y flags ===

COMPILER = g++

INCLUDE_DIR = include/
INCLUDE_FLAGS = $(shell find $(INCLUDE_DIR) -type d -printf '-I%p ')
FLAGS = -Wall -g $(INCLUDE_FLAGS)

# === Directorios ===
SRC_DIR = src/
OBJ_DIR = obj/
BIN_DIR = bin/
DELIVERABLE_DIR = deliverable/

# === Archivos fuente, objetos y ejecutable ===
SRCS := $(shell find $(SRC_DIR) -name '*.cpp')
OBJS := $(patsubst $(SRC_DIR)%, $(OBJ_DIR)%, $(SRCS:.cpp=.o))
MAIN_BIN := $(BIN_DIR)main.bin

# === Regla principal ===
todo: $(OBJ_DIR) $(BIN_DIR) $(MAIN_BIN)

# === Enlazado del ejecutable ===
$(MAIN_BIN): $(OBJS)
	$(COMPILER) $(FLAGS) -o $@ $^

# === Compilación de .cpp → .o con generación de .d ===
$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(dir $@)
	$(COMPILER) $(FLAGS) -MMD -MP -c $< -o $@

# === Inclusión de dependencias generadas (.d) ===
-include $(OBJS:.o=.d)

# === Crear carpetas raíz si no existen ===
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# === Limpieza: archivos generados y subdirectorios vacíos ===
clean:
	find $(OBJ_DIR) -type f \( -name '*.o' -o -name '*.d' \) -delete
	find $(OBJ_DIR) -type d -empty -not -path $(OBJ_DIR) -delete
	rm -f $(BIN_DIR)*.bin

# === Entregable ===

DELIVERABLE_ZIP = zip -r
DELIVERABLE_TAR = tar -czvf
EXCLUDE_ZIP = -x "*/.gitkeep"
EXCLUDE_TAR = --exclude="*/.gitkeep"
DELIVERABLE_FILE = grupo3_lab5
TEAM_MEMBERS = integrantes.txt

createEntregaZip: $(DELIVERABLE_DIR)
	$(DELIVERABLE_ZIP) $(DELIVERABLE_DIR)$(DELIVERABLE_FILE).zip $(SRC_DIR) $(INCLUDE_DIR) Makefile $(TEAM_MEMBERS) $(EXCLUDE_ZIP)

createEntregaTar: $(DELIVERABLE_DIR)
	$(DELIVERABLE_TAR) $(DELIVERABLE_DIR)$(DELIVERABLE_FILE).tar.gz $(EXCLUDE_TAR) $(SRC_DIR) $(INCLUDE_DIR) Makefile $(TEAM_MEMBERS)

$(DELIVERABLE_DIR):
	mkdir -p $(DELIVERABLE_DIR)

cleanEntrega:
	rm -rf $(DELIVERABLE_DIR)