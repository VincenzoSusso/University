@extends('layouts.app')

@section('page_title', 'I Miei Hobby - Home')
@section('page_description', 'Pagina principale del social network \"I Miei Hobby\"')

@section('content')
    <div class="container">
        <div class="row justify-content-center">
            <div class="col-md-8">
                <div class="card">
                    <div class="card-body">
                        <?php
                            if (isset(auth()->user()->name)) {
                                echo "Benvenuto " . auth()->user()->name;
                            } else {
                                echo 'I miei Hobby';
                            }
                        ?>
                    </div>
                </div>
            </div>
        </div>
@endsection
