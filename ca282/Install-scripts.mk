dst = $(HOME)/local/bin
src = $(wildcard [a-z]*)

install: $(dst) $(addprefix $(dst)/, $(src))
	@true

$(dst)/%: %
	install -v -m 0555 $< $@

$(dst):
	mkdir -vp $@

.PHONY: install
