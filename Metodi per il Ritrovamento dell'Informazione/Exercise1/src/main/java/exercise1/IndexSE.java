package exercise1;

import org.apache.lucene.analysis.standard.StandardAnalyzer;
import org.apache.lucene.document.Document;
import org.apache.lucene.document.Field;
import org.apache.lucene.document.StringField;
import org.apache.lucene.document.TextField;
import org.apache.lucene.index.IndexWriter;
import org.apache.lucene.index.IndexWriterConfig;
import org.apache.lucene.store.FSDirectory;

import java.io.File;
import java.io.FileReader;
import java.util.Objects;

public class IndexSE {
    public static void main(String[] args) {
        try {
            if (args.length == 2) {
                File directory = new File(args[0]);
                if (directory.isDirectory()) {
                    FSDirectory fsDirectory = FSDirectory.open(new File(args[1]).toPath());

                    IndexWriterConfig indexWriterConfig = new IndexWriterConfig(new StandardAnalyzer());
                    indexWriterConfig.setOpenMode(IndexWriterConfig.OpenMode.CREATE);

                    IndexWriter indexWriter = new IndexWriter(fsDirectory, indexWriterConfig);

                    for (File file : Objects.requireNonNull(directory.listFiles())) {
                        if (file.isFile() && file.getName().endsWith(".txt")) {
                            Document document = new Document();
                            document.add(new StringField("id", file.getAbsolutePath(), Field.Store.YES));
                            document.add(new TextField("text", new FileReader(file)));
                            indexWriter.addDocument(document);
                            System.out.println("Added document" + file.getAbsolutePath());
                        }
                    }

                    indexWriter.close();
                    System.out.println("The index is now created");

                } else {
                    throw new IllegalArgumentException("The first argument must be the directory name where the files " +
                            "are stored");
                }
            } else {
                throw new IllegalArgumentException("There must be two argoments:\n\t1: The first argument must be the " +
                        "directory name where the files are stored\n\t2: The second argument must be the path where the " +
                        "index will be stored");
            }
        } catch (Exception e) {
            System.err.println(e.getLocalizedMessage());
        }
    }
}
