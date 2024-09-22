import sentencepiece as spm

def train_sentencepiece(corpus_files, model_prefix, vocab_size=200000):
    spm.SentencePieceTrainer.train(
        f"--input={','.join(corpus_files)} --model_prefix={model_prefix} --vocab_size={vocab_size} --character_coverage=1.0 --model_type=bpe"
    )
#load the sp model to train on the dataset initally
if __name__ == "__main__":
    corpus_files = ['Large_english_copra_stackoverflow.txt', 'Large_english_corpus.txt']
    train_sentencepiece(corpus_files, "models/spm_model_combined", vocab_size=200000)