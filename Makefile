.PHONY: clean All

All:
	@echo "----------Building project:[ nnumber2ndApproach - Debug ]----------"
	@cd "nnumber2ndApproach" && "$(MAKE)" -f  "nnumber2ndApproach.mk"
clean:
	@echo "----------Cleaning project:[ nnumber2ndApproach - Debug ]----------"
	@cd "nnumber2ndApproach" && "$(MAKE)" -f  "nnumber2ndApproach.mk" clean
