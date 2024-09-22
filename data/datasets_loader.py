from datasets import load_dataset
dataset = load_dataset("wikitext", "wikitext-103-raw-v1")

with open("Large_english_corpus.txt", "a", encoding="utf-8") as file:
    for data in dataset['train']:
        text = data['text'] 
        file.write("## Source: Wikitext\n")
        file.write(text + "\n")