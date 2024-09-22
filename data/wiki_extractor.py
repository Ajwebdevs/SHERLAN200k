from datasets import load_dataset
stackoverflow_ds = load_dataset("mirzaei2114/stackoverflowVQA-filtered", split="train")

with open("Large_english_copra_stackoverflow.txt", "w", encoding="utf-8") as stack_file:
    for entry in stackoverflow_ds:
        question = entry.get('Question', '').strip()  
        answer = entry.get('Answer', '').strip()     

        if question and answer:
            stack_file.write("##source: StackOverflow\n")
            stack_file.write("Question: " + question + "\n")
            stack_file.write("Answer: " + answer + "\n")
            stack_file.write("\n")  