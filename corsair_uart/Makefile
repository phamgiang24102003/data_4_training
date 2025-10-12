export PYTHONPATH := ../../.:$(PYTHONPATH)

all: generate

generate:
	python3 -m corsair -c csrconfig

clean:
	@rm -rf hw/regs_uart.v

.PHONY: all generate clean
