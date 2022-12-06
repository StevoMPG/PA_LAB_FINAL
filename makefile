################################################################

program   := 4_lab4
compiler  := g++
flags     := -std=c++20 -Wfatal-errors

src_dir   := src
obj_dir   := obj
dep_dir   := dep

src_files := $(shell find $(src_dir) -name "*.cpp" )
obj_files := $(patsubst $(src_dir)/%.cpp, $(obj_dir)/%.o, $(src_files) )
dep_files := $(patsubst $(src_dir)/%.cpp, $(dep_dir)/%.d, $(src_files) )

################################################################

# -include $(dep_files)

################################################################

# $(dep_dir)%.d: $(src_dir)/%.cpp
# 	@ mkdir -p $(@D)
# 	$(compiler) $^ -MD -MP -MF $@

################################################################

$(obj_dir)/%.o: $(src_dir)/%.cpp # $(dep_dir)/%.d
	@ mkdir -p $(@D)
	@ $(compiler) $(flags) -o $@ -c $< 2>&1 | tee log.txt

################################################################

$(program): $(obj_files)
	@ $(compiler) $(flags) -o $(program) $^ 2>&1 | tee log.txt

################################################################

all: build

################################################################

build: $(program)

################################################################

run: $(program)
	@ ./$(program)

################################################################

clean:
	@ rm -rf core $(program).exe $(program) $(obj_dir) $(dep_dir) log.txt

################################################################

rebuild: clean build

################################################################

.PHONY: all build clean rebuild run

################################################################