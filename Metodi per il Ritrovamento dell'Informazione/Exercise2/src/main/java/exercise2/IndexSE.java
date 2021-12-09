package exercise2;

import org.apache.lucene.analysis.standard.StandardAnalyzer;
import org.apache.lucene.document.*;
import org.apache.lucene.index.IndexWriter;
import org.apache.lucene.index.IndexWriterConfig;
import org.apache.lucene.store.FSDirectory;

import java.io.File;
import java.io.FileReader;
import java.util.Objects;

public class IndexSE {
    public static void main(String[] args) {
        try {
            if (args.length == 3) {
                File directory = new File(args[0]);
                if (directory.isDirectory()) {
                    FSDirectory fsDirectory = FSDirectory.open(new File(args[1]).toPath());

                    IndexWriterConfig indexWriterConfig = new IndexWriterConfig(new StandardAnalyzer());
                    indexWriterConfig.setOpenMode(IndexWriterConfig.OpenMode.CREATE);

                    IndexWriter indexWriter = new IndexWriter(fsDirectory, indexWriterConfig);

                    String thirdArgument = args[2].toLowerCase();
                    FieldType fieldType = new FieldType(TextField.TYPE_NOT_STORED);
                    fieldType.setTokenized(true);
                    fieldType.setStoreTermVectors(true);
                    if (!thirdArgument.equals("tv")) {
                        if (thirdArgument.equals("tvp")) {
                            fieldType.setStoreTermVectorPositions(true);
                        } else if (thirdArgument.equals("tvo")) {
                            fieldType.setStoreTermVectorPositions(true);
                            fieldType.setStoreTermVectorOffsets(true);
                        } else {
                            throw new IllegalArgumentException("The third argument can be:\n\ttv -> only term vector" +
                                    "\n\ttvp: term vector with positions\n\ttvo: term vector with positions and" +
                                    "offsets");
                        }
                    }

                    File[] files = directory.listFiles();
                    if (files != null) {
                        for (File file : files) {
                            if (file.isFile() && file.getName().endsWith(".txt")) {
                                Document document = new Document();
                                document.add(new StringField("id", file.getAbsolutePath(), Field.Store.YES));
                                //document.add(new TextField("text", new FileReader(file)));
                                document.add(new Field("text", new FileReader(file), fieldType));
                                indexWriter.addDocument(document);
                            }
                        }
                    }

                    indexWriter.close();
                    fsDirectory.close();
                    System.out.println("The index is now created");

                } else {
                    throw new IllegalArgumentException("The first argument must be the directory name where the files " +
                            "are stored");
                }
            } else {
                throw new IllegalArgumentException("There must be three argoments:\n\t1: The first argument must be the " +
                        "directory name where the files are stored\n\t2: The second argument must be the path where the " +
                        "index will be stored\n\t3: The third argument must be the term vector option");
            }
        } catch (Exception e) {
            System.err.println(e.getLocalizedMessage());
        }
    }
}
